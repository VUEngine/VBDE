::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL %~dp0\init.bat

::LAUNCH VIDE
PUSHD %VBDE%\tools\graphics\vide\
START "" "VIDE.EXE"