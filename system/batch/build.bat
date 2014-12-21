::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::SWITCH TO PROJECT DIRECTORY
PUSHD %PROJECT_DIR%

::PRE CLEAN
IF EXIST output.vb DEL output.vb
IF EXIST output_pad.vb DEL output_pad.vb
IF EXIST output.o DEL output.o
IF EXIST output.ram DEL output.ram

::BUILD ROM
IF EXIST makefile (
	::allow project to have its own makefile
	%VBDE%\cygwin\bin\bash -l -c "export VBDE=$(cygpath -u '%VBDE%') && make all"
) ELSE (
	::otherwise use default makefile
	%VBDE%\cygwin\bin\bash -l -c "export VBDE=$(cygpath -u '%VBDE%') && make -f $VBDE/system/makefile SOURCE=%2"
)

::SET ROM HEADER
IF EXIST output.vb IF EXIST header (
	SETLocal EnableDelayedExpansion
	FOR /f "tokens=* delims= " %%a in (header) do (
		SET /a N+=1
		SET v!N!=%%a
	)
	vbid output.vb "!v4!" - !v6! !v8! !v10!
)

::POST CLEAN
IF EXIST output.o DEL output.o

::RUN IN EMULATOR IF ROM COULD BE COMPILED
IF EXIST output.vb IF EXIST %VBDE%\system\batch\launch-%3.bat (
	CALL %VBDE%\system\batch\launch-%3.bat %PROJECT_DIR%
)

::DO NOT CLOSE CMD WINDOW IF ROM COULD NOT BE COMPILED
IF NOT EXIST output.vb (
	pause > nul
)