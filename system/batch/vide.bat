::SCRIPT INITIALIZATION
@echo off
SET VBDE=C:\vbde
CALL %VBDE%\system\batch\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::LAUNCH VIDE
PUSHD %VBDE%\tools\graphics\vide\
START "" "VIDE.EXE"
