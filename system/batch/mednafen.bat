::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::LAUNCH MEDNAFEN
CALL %VBDE%\system\batch\launch-mednafen.bat