# (c) Advanced Tools Ltd., 2004-2013
# $Id: profile.tcl,v 1.16 2009/05/27 11:23:47 msk Exp $

echo-off
#puts "profile"
#puts "base=path=$base_path"
#puts ${base_path}lib.tcl
source $base_path/lib.tcl
about-version

#include "$base_path/test/defs.h"
symtab
strtab
option -reuse_env_unused
option +reuse_env
hilight
echo-on
