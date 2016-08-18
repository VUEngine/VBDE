::SET ECHO OFF
@echo off

ECHO Starting build process...

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::SWITCH TO PROJECT DIRECTORY
PUSHD %PROJECT_DIR%

::PREPARE ENV VARS
SET VBDE_UNIX=%VBDE:\=/%
SET VBDE_UNIX=%VBDE_UNIX:c:=/c%
ECHO VBDE directory: %VBDE_UNIX%

SET PROJECT_DIR_UNIX=%PROJECT_DIR:\=/%
SET PROJECT_DIR_UNIX=%PROJECT_DIR_UNIX:c:=/c%
ECHO Project directory: %PROJECT_DIR_UNIX%

set MSYSTEM=MINGW32

::BUILD ROM
IF EXIST makefile (
	::allow projects to have their own makefile
    ECHO Using custom makefile
	%VBDE%\system\msys32\usr\bin\bash.exe --login -c "export MSYSTEM=MSYS && cd %PROJECT_DIR_UNIX% && export VBDE=$VBDE_UNIX && export PATH=$PATH:/v810/v810-win32/bin && /usr/bin/make all"
) ELSE (
	::otherwise use default makefile
    ECHO Using default makefile
	%VBDE%\system\msys32\usr\bin\bash.exe --login -c "cd %PROJECT_DIR_UNIX% && export VBDE=$VBDE_UNIX && export PATH=$PATH:/v810/v810-win32/bin && /usr/bin/make all -f $VBDE/system/makefile"
	)

::SET ROM HEADER
IF EXIST build\output.vb IF EXIST header (
	SETLocal EnableDelayedExpansion
	FOR /f "tokens=* delims= " %%a in (header) do (
		SET /a N+=1
		SET v!N!=%%a
	)
	%VBDE%\tools\rom\vbid-1.0-win\vbid build\output.vb "!v4!" - !v6! !v8! !v10! > nul
)

::RUN IN EMULATOR IF ROM COULD BE COMPILED
IF EXIST build\output.vb IF EXIST %VBDE%\system\batch\launch-%3.bat (
	CALL %VBDE%\system\batch\launch-%3.bat %PROJECT_DIR%
)

::DO NOT CLOSE CMD WINDOW IF ROM COULD NOT BE COMPILED
IF NOT EXIST build\output.vb (
	pause > nul
)
