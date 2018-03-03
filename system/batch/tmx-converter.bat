::SET ECHO OFF
@echo off

ECHO CONVERTING STAGES...

::SCRIPT INITIALIZATION
CALL "%~dp0\init.bat"

::FIND PROJECT DIRECTORY
CALL "%VBDE%\system\batch\find-project-dir.bat" %1

::SWITCH TO PROJECT DIRECTORY
PUSHD "%PROJECT_DIR%"

::CONVERT TILED STAGES
CALL "%VBDE%\system\batch\launch-tmx-converter.bat"
