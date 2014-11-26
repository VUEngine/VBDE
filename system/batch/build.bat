::SET ECHO OFF
@echo off

::SET TEMPORARY ENVIRONMENT VARIABLES
SET VBDE=C:\vbde
SET PATH=%PATH%;%VBDE%\cygwin\bin;%VBDE%\tools\rom\vbid-1.0-win
SET C_INCLUDE_PATH=%VBDE%\libs\libgccvb

::SET TEMPORARY CYGWIN ENVIRONMENT VARIABLES
SET CYGWIN=nodosfilewarning
SET CHERE_INVOKING=1

::SWITCH TO PROJECT DIRECTORY
PUSHD %1

::PRE CLEAN
IF EXIST output.vb DEL output.vb
IF EXIST output_pad.vb DEL output_pad.vb
IF EXIST output.o DEL output.o

::CONVERT IMAGES
CALL %VBDE%\system\batch\grit.bat
PUSHD %1

::BUILD ROM
IF EXIST makefile (
	::allow project to have its specific makefile
	%VBDE%\cygwin\bin\bash -l -c "mkpasswd -l > /etc/passwd &&  mkgroup -l > /etc/group && export VBDE=$(cygpath -u '%VBDE%') && make all"
) ELSE (
	::otherwise use default makefile
	%VBDE%\cygwin\bin\bash -l -c "mkpasswd -l > /etc/passwd &&  mkgroup -l > /etc/group && export VBDE=$(cygpath -u '%VBDE%') && make -f $VBDE/system/makefile SOURCE=%2"
)

::SET ROM HEADER
IF EXIST output.vb AND EXIST header (
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
IF EXIST output.vb AND EXIST %VBDE%\system\batch\%3.bat (
	CALL %VBDE%\system\batch\%3.bat %1
)

::DO NOT CLOSE CMD WINDOW IF ROM COULD NOT BE COMPILED
IF NOT EXIST output.vb (
	pause > nul
)
