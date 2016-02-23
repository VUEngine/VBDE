::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::SET CONFIG FILE TO WRITE TO
SET CONFIG_FILE=%PROJECT_DIR%\.idea\misc.xml

::DETERMINE LIBRARY TYPE (TODO: FIND A BETTER WAY)
SET LIBRARY=libgccvb
IF EXIST %PROJECT_DIR%\config.h (
    SET LIBRARY=vbjaengine
)

::PRINT CONFIG FILE HEADER
ECHO ^<?xml version="1.0" encoding="UTF-8"?^> > %CONFIG_FILE%
ECHO ^<project version="4"^> >> %CONFIG_FILE%
ECHO ^<component name="CppTools.Loader" reportImplicitCastToBool="false" reportNameNeverReferenced="false" reportNameReferencedOnce="false" reportRedundantCast="false" reportRedundantQualifier="false" reportStaticCallFromInstance="false" reportDuplicatedSymbols="false" warnedAboutFileOutOfSourceRoot="true" version="3" currentProject="$PROJECT_DIR$/makefile" sdkErrorReported="true" additionalPreprocessorDefs="" automaticallyIncludedHeaderFiles=^" >> %CONFIG_FILE%

::PRINT H FILES THAT HAVE NO CORRESPONDING C FILE, IGNORE FOLDERS STARTING WITH .
FOR /f "delims=" %%D IN ('dir /s /b /o:n /a-d "%VBDE%\cygwin\opt\gccvb\v810\include\<.h" "%VBDE%\libs\%LIBRARY%\<.h" "%PROJECT_DIR%\<.h"') DO (
    (ECHO "%%D" | FIND /I "\." 1>NUL) || (
        ::IF NOT EXIST %%~dpnD.c
        ECHO %%D; >> %CONFIG_FILE%
    )
)

::PRINT CONFIG FILE HEADER CLOSING
ECHO ^" compilerSelect="GCC" javaIncludes="false"^> >> %CONFIG_FILE%

::PRINT RECURSIVE FOLDERS INCLUDE, IGNORE FOLDERS STARTING WITH .
ECHO ^<system-include-dir path="%VBDE%\libs\%LIBRARY%" /^> >> %CONFIG_FILE%
ECHO ^<system-include-dir path="%PROJECT_DIR%" /^> >> %CONFIG_FILE%
FOR /f "delims=" %%D IN ('dir /s /b /o:n /ad "%VBDE%\libs\%LIBRARY%" "%PROJECT_DIR%"') DO (
    (ECHO "%%D" | FIND /I "\." 1>NUL) || (
        ECHO ^<system-include-dir path="%%D" /^> >> %CONFIG_FILE%
    )
)

::PRINT FOOTER
ECHO ^</component^> >> %CONFIG_FILE%
ECHO ^</project^> >> %CONFIG_FILE%

::CONSOLE OUTPUT
ECHO "Done indexing project"
