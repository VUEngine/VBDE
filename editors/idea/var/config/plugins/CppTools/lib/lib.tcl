# (c) Advanced Tools Ltd., 2004-2013

proc about-version {} {
    global argv
    about "Command: [cfserver] $argv" "Library: \$Id: lib.tcl, 2010/11/26 14:27 shd Exp $"
}

proc null {} {
    global machine
    if {![string compare $machine ""]} {
        fail "Error: check_gcc_compiler should be called before null"
        return "nul"
    }

    if {[file readable /dev/null]} {
	return "/dev/null"
    }
    if {![file readable nul]} {
	fail "Error: /dev/null and nul are unaccessible"
    }

    if {[string compare $machine "cygwin"]} {
	return "nul"
    } else {
	return "/dev/null"
    }
}

proc filename_quote_for_shell {name} {
    regsub -all {\\} $name {\\\\} name
    regsub -all {\"} $name {\\\"} name
    regsub -all {\'} $name {\\\'} name
    return "\"$name\""
}

proc execute_gcc_default_fail {cmd msg error} {
    fail "Cannot execute command `$cmd': `$msg'. Output:\n$error"
}

# Perform gcc command and call either line_func for each line of the input
# or fail_func, if the command could not be called
proc execute_gcc {gcc_command args message line_func fail_func} {
    set result {}
    set error ""
    set full_cmd "|[filename_quote_for_shell $gcc_command] $args |& [cfserver] --cat"
    set cwd [pwd]

    cd [file dirname $gcc_command]
    if {[catch {set f [open $full_cmd "r"]} error]} {
	cd $cwd
	$fail_func $full_cmd $message $error
	return 0
    } else {
	set result [list 1]
	while {[expr ![eof $f]]} {
	    set ln [gets $f]
	    set error "$error\n$ln"
	    $line_func $ln
	}
	cd $cwd
        set errorlevel [catch {close $f}]
	if {$errorlevel} {
	    fail "Command '$full_cmd' exited with non-zero exit code and output:\n$error"
	    return 0
	}
	return 1
    }
}

proc check_gcc_linefunc {str} {
    global machine
    switch -regexp -- $str {
	"cygwin"	{ set machine "cygwin" }
	"mingw"		{ set machine "mingw" }
	"linux"		{ set machine "linux" }
    }
}

proc check_gcc_fail {cmd msg err} {
    echo-off
    error 1 "Could not execute gcc compiler: command $cmd, $msg, output: $err"
    echo-on
}

proc check_gcc_compiler {message command} {
    global machine
    set machine "unknown"
    return [execute_gcc $command "-dumpmachine" $message check_gcc_linefunc check_gcc_fail]
}

proc cfserver {} {
    return [filename_quote_for_shell [info nameofexecutable]]
}

proc gcc-sys-include {name} {
    system-include-path $name
#   puts "System: $name"
}

proc gcc-user-include {name} {
    user-include-path $name
#   puts "User: $name"
}

proc prepare-path {path} {
    global env
    set path [string trim $path]
    if {[info exists env(OS)]
	&& [string match "Windows_NT" $env(OS)]
	&& [string match "/*" $path]
    } {
	catch {set path [exec cygpath -w $path]}
    }
    return $path
}

proc get-gcc-includes-linefunc {ln} {
    global sys_user
#   puts $ln
#   puts $sys_user
    switch -regexp -- $ln {
	"#include \"\.\.\.\"" { set sys_user 2 }
	"#include <\.\.\.>" { set sys_user 1 }
        "^[^ ]" { set sys_user 0 }
        "^ .*" {
	    switch $sys_user {
	    1	{ gcc-sys-include [prepare-path $ln] }
	    2	{ gcc-user-include [prepare-path $ln] }
	    }
        }
    }
}

proc get-gcc-includes {cmd lang standard} {
    global sys_user
    set sys_user 0
    return [execute_gcc $cmd " -x $lang $standard -E -v [null]" "" get-gcc-includes-linefunc execute_gcc_default_fail]
}

proc process-define {ln} {
    if {[regexp "#define (\[^ \]+)\[ \]+(.*)" $ln temp name args]} {
        define $name $args
#       puts "define \"$name\" \"$args\""
    }
#   puts $ln
    return $ln
}

proc get-gcc-defines {cmd lang standard} {
    define __PRETTY_FUNCTION__ "some_function"
    return [execute_gcc $cmd " -x $lang $standard -E -dM [null]" "" process-define execute_gcc_default_fail]
}

proc define-date-time {} {
    set clk [clock scan now]
    set rdate [clock format $clk -format "\"%b %e %Y\""]
    set rtime [clock format $clk -format "\"%H:%M:%S\""]
    #puts $rdate
    #puts $rtime
    define __LINE__ (0)
    define __FILE__ \"__FILE__\"
    define __DATE__ $rdate
    define __TIME__ $rtime
}

proc gnu_lang {lang command args} {
    if {$lang == "-n"} {
       return [eval gnu_lang $args]

    }
    set flags ""
    set exe_name $command
    set standard ""
    for {set i 0} {$i+1 < [llength $args]} {incr i} {
	switch -regexp -- [lindex $args $i] {
	    "^-n$"	{ incr i; set flags "-n [lindex $args $i]" }
	    "^-c$"	{ incr i; set exe_name [lindex $args $i] }
	    "^-s$"	{ incr i; set standard [lindex $args $i] }
	    "^-"	{ fail "$command: unknown option [lindex $args $i]" }
	    -		{ break }
	}
    }

    eval begin-command $flags $command

    set std_option "-std=$standard"
    set server_lang $lang
    switch -- $standard {
	"c90"	-
	"c89"	-
	"iso9899:1990"	-
	"iso9899:199409"	{ set server_lang "c90" }

	"c99"	-
	"c9x"	-
	"iso9899:1999"	-
	"iso9899:199x"		{ set server_lang "c99" }

	"c11"	-
	"c1x"	-
	"iso9899:2011"		{ set server_lang "c11" }

	"gnu90"	-
	"gnu89"			{ set server_lang "c90" }

	"gnu99"	-
	"gnu9x"			{ set server_lang "c99" }

	"gnu11"	-
	"gnu1x"			{ set server_lang "c11" }

	"c++98"	-
	"c++03"	-
	"gnu++98"	-
	"gnu++03"		{ set server_lang "c++98" }

	"c++11"	-
	"c++0x"	-
	"gnu++11"	-
	"gnu++0x"		{ set server_lang "c++1x" }

	"c++1y" -
	"gnu++1y"		{ set server_lang "c++1y" }

	""			{ set server_lang $lang; set std_option "" }
	default			{ fail "$command: unknown c/c++ standard $standard" }
    }

    language $server_lang gnu
    user-include-path-mode current
    include [base_path]/__cpptools_server_defs.h
    define-date-time
    define __STDC__ 1
    if {[check_gcc_compiler "GNU compiler \'$exe_name\' not found. Use -c option or check path." $exe_name]} {
        get-gcc-includes $exe_name $lang $std_option
        get-gcc-defines $exe_name $lang $std_option
    }

    end-command $command
}

proc gcc {args} {
    eval gnu_lang "c" "gcc" $args
}

proc g++ {args} {
    eval gnu_lang "c++" "g++" $args
}

set VC "/home/msk/VisualC/VC"
proc vc++ {args} {
    eval begin-command $args vc++
    language c++ visual
    define-date-time
    define __STDC__ 1
    define __cplusplus 1
    define _cdecl __cdecl
    define _stdcall __stdcall
    define _MSC_VER 2000
    define interface class
    define __single_inheritance ""
    define __multiple_inheritance ""
    define __virtual_inheritance ""
    define __pin ""
    define __FUNCSIG__ \"__FUNCSIG__\"
    define __int64 long long
    define __export ""
    define __forceinline __inline
    define alloca _alloca
    use-abs-path
    user-include-path-mode visited
    end-command vc++
}

proc vc {args} {
    eval begin-command $args vc
    language c visual
    define-date-time
    define __STDC__ 1
    define _cdecl __cdecl
    define _stdcall __stdcall
    define _MSC_VER 2000
    define interface class
    define __single_inheritance ""
    define __multiple_inheritance ""
    define __virtual_inheritance ""
    define __pin ""
    define __FUNCSIG__ \"__FUNCSIG__\"
    define __int64 long long
    define __export ""
    define __forceinline __inline
    define alloca _alloca
    use-abs-path
    user-include-path-mode visited
    end-command vc
}

set VC6 "/home/msk/VC/VC98"
proc vc6++ {args} {
    eval begin-command $args vc++
    language c++ visual

    define-date-time
    define __STDC__ 1
    define __cplusplus 1
    define _MSC_VER 2000
    define interface class
    define __single_inheritance ""
    define __multiple_inheritance ""
    define __virtual_inheritance ""
    define __pin ""
    define __FUNCSIG__ \"__FUNCSIG__\"
    define __export ""
    define alloca _alloca
    define __forceinline __inline
    define __int64 long long
    define _cdecl __cdecl
    define _stdcall __stdcall
    use-abs-path
    user-include-path-mode visited
    end-command vc++
}

proc VSIP {} {
    global VC
    set vsip "$VC/../VSIP"
    system-include-path "$vsip/EnvSDK/common/inc"
}

proc modules_impl {path rec pattern verbose} {
    set glob_dir [file join $path [file dirname $pattern]]
    set glob_pattern [file tail $pattern]
    foreach fname [glob -nocomplain -types f -directory $glob_dir -- "$glob_pattern"] {
	if {$verbose == 1} {puts $fname}
        module $fname
    }
    if {$rec == 1} {
        set all_dirs [glob -nocomplain -types d -directory $path -- "*"]
        foreach dname $all_dirs {
#           puts "Entering $dname"
            modules_impl $dname $rec $pattern $verbose
#           puts "Exiting $dname"
        }
    }
}

proc modules {args} {
    set flags ""
    set start [project_path]
    set n -1
    set rec 0
    set verbose 0

    for {set i 0} {$i < [llength $args]} {incr i} {
	switch -regexp -- [lindex $args $i] {
	    "^-n$"	{ incr i; set flags "-n [lindex $args $i]" }
	    "^-r$"	{ set rec 1 }
	    "^-d$"	{ incr i; set start [lindex $args $i] }
	    "^-v$"	{ set verbose 1 }
	    "^--$"	{ break }
	    "^-"	{ fail "modules: unknown option [lindex $args $i]" }
	    default	{ break }
	}
    }

    eval begin-command $flags modules
    set start [file normalize $start]
    for {} {$i < [llength $args]} {incr i} {
        modules_impl $start $rec [lindex $args $i] $verbose
    }
    end-command modules
}

set project_path "."

proc load-project {args} {
    eval begin-command $args load-project
    global project_path
    set p [file normalize "."]
    while {true} {
	set fl [file join $p ".cf-project"]
	#puts $fl

	if {[file exists $fl]} {
	    set project_path $p
            #puts "Project path = $project_path"
	    set-project-dir $project_path
	    source $fl
	    break
	} {}

	set p1 [file dirname $p]
	if {[expr {$p1 == $p}]} {
	    g++
	    modules *.cpp
	    modules *.C
	    modules *.c
	    break
	} {}
	set p $p1
    }
    end-command load-project
}

proc base_path {} {
    global base_path
    set base_path [file normalize $base_path]
    return $base_path
}

proc project_path {} {
    global project_path
    return $project_path
}

proc timed-script {script args} {
    if {[catch {set p [open "|[cfserver] $args" w]} error]} {
	fail "Error executing '[cfserver] $args': $error"
    } {
    	if {[catch {set f [open $script]} error]} {
    	    close $p
    	    fail "Error reading script '$script': $error"
    	} {
    	    fconfigure $p -blocking 1
            while {[expr ![eof $f]]} {
            	set ln [gets $f]
		if {[regexp "^#timer: (\[0-9.\]+)" $ln _ time]} {
		    puts "#status: waiting till $time ..."
		    wait_timer $time
		} {
		    puts "#status: command $ln"
		    puts $p $ln
		    flush $p
		}
            }
    	    close $f
    	    close $p
    	}
    }
}
