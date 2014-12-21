::SET ECHO OFF
@echo off

::SET DIRS
SET VBDE=%~dp0\..\..\

::SET TEMPORARY ENVIRONMENT VARIABLES
SET PATH=%PATH%;%VBDE%\cygwin\bin;%VBDE%\cygwin\opt\gccvb\bin;%VBDE%\tools\rom\vbid-1.0-win
SET C_INCLUDE_PATH=%VBDE%\cygwin\opt\gccvb\v810\include;%VBDE%\libs\libgccvb

::SET TEMPORARY CYGWIN ENVIRONMENT VARIABLES
SET CYGWIN=nodosfilewarning
SET CHERE_INVOKING=1
