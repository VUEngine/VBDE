::SET ECHO OFF
@echo off

::SET VBDE PATH BY FINDING THE PARENT DIR TWICE FROM THIS SCRIPT'S PATH
set "VBDE=%~dp0"
:char1
set VBDE=%VBDE:~0,-1%
IF "%VBDE:~-1%"=="\" ( goto end1 ) else ( goto char1 )
:end1
:char2
set VBDE=%VBDE:~0,-1%
IF "%VBDE:~-1%"=="\" ( goto end2 ) else ( goto char2 )
:end2
