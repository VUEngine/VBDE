IF EXIST assets\graphics\ (
	::switch to graphics directory
	CD assets\graphics\
	::pre clean
	DEL graphics.h
	DEL objects\* /q
	::create graphics header file
	ECHO // graphics >> graphics.h
	::convert all graphics
	FOR /r source\ %%F in (*.png *.bmp *.jpg *.jpeg *.gif *.pcx) do (
		C:\vbde\tools\graphics\grit-0.8.6\grit.exe %%F -o objects\%%~nF.s -gB2 -p! -mLs -mB16:p2hv_i11
		ECHO #include "objects/%%~nF.h" >> graphics.h
	)
	::switch back to project directory
	PUSHD %PROJECT_DIR%
)
