::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::GENERATE SSH KEYS IF NOT EXISTING YET
CALL %VBDE%\system\batch\ssh-keygen.bat

::SWITCH TO ENGINE DIRECTORY
PUSHD %VBDE%\libs\vbjaengine

::PULL
%VBDE%\cygwin\bin\bash -l -c "git pull"
