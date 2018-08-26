::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL "%~dp0\init.bat"

::FIND PROJECT DIRECTORY
CALL "%VBDE%\system\batch\find-project-dir.bat" %1

::SWITCH TO PROJECT DIRECTORY
PUSHD "%PROJECT_DIR%\build"

::PRE CLEAN
IF EXIST output_pad.vb (
	DEL output_pad.vb
)

::PAD ROM
START "" "%VBDE%\tools\rom\Pad_VB\Pad_VB.exe" output.vb 3

::LAUNCH FLASHBOY LOADER
START "" "%VBDE%\tools\rom\FlashBoy_20101102\FlashBoy.exe"
