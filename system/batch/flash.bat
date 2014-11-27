::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::SWITCH TO PROJECT DIRECTORY
PUSHD %PROJECT_DIR%

::PAD ROM
START %VBDE%\tools\rom\Pad_VB\Pad_VB.exe %PROJECT_DIR%\output.vb

::LAUNCH FLASHBOY LOADER
START %VBDE%\tools\rom\FlashBoy_20101102\FlashBoy.exe

EXIT
