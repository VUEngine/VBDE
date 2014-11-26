::SCRIPT INITIALIZATION
@echo off
SET VBDE=C:\vbde
CALL %VBDE%\system\batch\init.bat

::FIND PROJECT DIRECTORY
CALL %VBDE%\system\batch\find-project-dir.bat %1

::LAUNCH REALITY BOY
CALL %VBDE%\system\batch\launch-reality_boy.bat
