::SET ECHO OFF
@echo off

ECHO Cleaning up project...

::SCRIPT INITIALIZATION
CALL "%~dp0\init.bat"

::FIND PROJECT DIRECTORY
CALL "%VBDE%\system\batch\find-project-dir.bat" %1

::DELETE PROJECT'S BUILD DIRECTORY
RMDIR /S /Q "%PROJECT_DIR%\build"
