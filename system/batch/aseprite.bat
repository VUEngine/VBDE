::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL "%~dp0\init.bat"

::GO TO ASEPRITE DIRECTORY
PUSHD "%VBDE%\tools\graphics\aseprite-0.9.5-win32\"

::CHECK IF PASSED FILE IS IMAGE AND LAUNCH ASEPRITE
FOR %%i IN ("%1") DO (

  set "IS_IMAGE="
  IF "%%~xi" == ".bmp" SET IS_IMAGE=1
  IF "%%~xi" == ".gif" SET IS_IMAGE=1
  IF "%%~xi" == ".jpg" SET IS_IMAGE=1
  IF "%%~xi" == ".jpeg" SET IS_IMAGE=1
  IF "%%~xi" == ".pcx" SET IS_IMAGE=1
  IF "%%~xi" == ".png" SET IS_IMAGE=1

  IF DEFINED IS_IMAGE (
    START "" "aseprite.exe" "%1"
  ) ELSE (
    START "" "aseprite.exe"
  )

)
