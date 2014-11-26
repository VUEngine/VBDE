::SCRIPT INITIALIZATION
@echo off
SET VBDE=C:\vbde
call %VBDE%\system\batch\init.bat

::SWITCH TO PROJECT DIRECTORY
CD %1

IF EXIST assets\graphics\ (
	::switch to graphics directory
	CD assets\graphics\
	::pre clean
	DEL graphics.h
	DEL objects\* /q
	::create graphics header file
	echo // graphics >> graphics.h
	::convert all graphics
	FOR /r source\ %%F in (*.png *.bmp *.jpg *.jpeg *.gif *.pcx) do (
		C:\vbde\tools\graphics\grit-0.8.6\grit.exe %%F -o objects\%%~nF.s -gB2 -p! -mLs -mB16:p2hv_i11
		echo #include "objects/%%~nF.h" >> graphics.h
	)
	::switch back to project directory
	CD %1
)