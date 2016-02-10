::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::SET CONFIG FILE TO WRITE TO
SET CONFIG_FILE=%PROJECT_DIR%\.idea\misc.xml


::PRINT CONFIG FILE HEADER
ECHO ^<?xml version="1.0" encoding="UTF-8"?^> > %CONFIG_FILE%
ECHO ^<project version="4"^> >> %CONFIG_FILE%
ECHO ^<component name="CppTools.Loader" reportImplicitCastToBool="false" reportNameNeverReferenced="false" reportNameReferencedOnce="false" reportRedundantCast="false" reportRedundantQualifier="false" reportStaticCallFromInstance="false" reportDuplicatedSymbols="false" warnedAboutFileOutOfSourceRoot="true" version="3" currentProject="$PROJECT_DIR$/makefile" sdkErrorReported="true" additionalPreprocessorDefs="" automaticallyIncludedHeaderFiles=^" >> %CONFIG_FILE%

::PRINT VBJAENGINE H FILES THAT HAVE NO CORRESPONDING C FILE
FOR /f "delims=" %%D IN ('dir /s /b /o:n /a-d "%VBDE%\libs\vbjaengine\source\<.h"') DO (
    ::IF NOT EXIST %%~dpnD.c
    ECHO %%D; >> %CONFIG_FILE%
)

::PRINT PROJECT H FILES THAT HAVE NO CORRESPONDING C FILE
FOR /f "delims=" %%D IN ('dir /s /b /o:n /a-d "%PROJECT_DIR%\<.h"') DO (
    ::IF NOT EXIST %%~dpnD.c
    ECHO %%D; >> %CONFIG_FILE%
)

::PRINT CONFIG FILE HEADER CLOSING
ECHO ^" compilerSelect="GCC" javaIncludes="false"^> >> %CONFIG_FILE%


::PRINT VBJAENGINE MAIN FOLDER INCLUDE
ECHO ^<system-include-dir path="%VBDE%\libs\vbjaengine" /^> >> %CONFIG_FILE%

::PRINT RECURSIVE VBJAENGINE FOLDERS INCLUDE
FOR /f "delims=" %%D IN ('dir /s /b /o:n /ad "%VBDE%\libs\vbjaengine\assets" "%VBDE%\libs\vbjaengine\source"') DO (
    ECHO ^<system-include-dir path="%%D" /^> >> %CONFIG_FILE%
)

::PRINT PROJECT MAIN FOLDER INCLUDE
ECHO ^<system-include-dir path="%PROJECT_DIR%" /^> >> %CONFIG_FILE%

::PRINT RECURSIVE PROJECT FOLDERS INCLUDE
FOR /f "delims=" %%D IN ('dir /s /b /o:n /ad "%PROJECT_DIR%\assets" "%PROJECT_DIR%\source"') DO (
    ECHO ^<system-include-dir path="%%D" /^> >> %CONFIG_FILE%
)


::PRINT FOOTER
ECHO ^</component^> >> %CONFIG_FILE%
ECHO ^</project^> >> %CONFIG_FILE%


ECHO "Done indexing project"
