::SCRIPT INITIALIZATION
@echo off
SET VBDE=C:\vbde
call %VBDE%\system\batch\init.bat

::GENERATE SSH KEYS IF NOT EXISTING YET
call %VBDE%\system\batch\ssh-keygen.bat

::SWITCH TO ROOT DIRECTORY
PUSHD %VBDE%

::PULL
%VBDE%\cygwin\bin\bash -l -c "git pull"
