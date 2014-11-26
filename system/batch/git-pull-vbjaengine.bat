::SCRIPT INITIALIZATION
@echo off
SET VBDE=C:\vbde
CALL %VBDE%\system\batch\init.bat

::GENERATE SSH KEYS IF NOT EXISTING YET
CALL %VBDE%\system\batch\ssh-keygen.bat

::SWITCH TO ENGINE DIRECTORY
PUSHD %VBDE%\libs\vbjaengine

::PULL
%VBDE%\cygwin\bin\bash -l -c "git pull"
