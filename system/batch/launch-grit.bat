::SWITCH TO ASSETS DIRECTORY
PUSHD %PROJECT_DIR%

::CONVERT ASSETS
IF EXIST assets\images\ (

	::SWITCH TO IMAGES DIRECTORY
	PUSHD assets\images\

	::PREPARATIONS
	IF EXIST _o (
		DEL _o\* /q
	) ELSE (
		MKDIR _o
	)

	::CONVERT ALL IMAGES
	FOR /r . %%F in (*.png *.bmp *.jpg *.jpeg *.gif *.pcx) do (
		%VBDE%\tools\graphics\grit-0.8.6\grit.exe %%F -o _o\%%~nF -ftc -gB2 -mB16:hv_i11 -mRtf -p!
		ECHO #include "%%~nF.h" >> _o\_index.h
	)
)

::SWITCH TO ASSETS DIRECTORY
PUSHD %PROJECT_DIR%

::CONVERT ASSETS
IF EXIST assets\spritesheets\ (

	::SWITCH TO IMAGES DIRECTORY
	PUSHD assets\spritesheets\

	::PREPARATIONS
	IF EXIST _o (
		DEL _o\* /q
	) ELSE (
		MKDIR _o
	)

	::CONVERT ALL IMAGES
	FOR /r . %%F in (*.png *.bmp *.jpg *.jpeg *.gif *.pcx) do (
		%VBDE%\tools\graphics\grit-0.8.6\grit.exe %%F -o _o\%%~nF -ftc -gB2 -mB16:i11 -mR! -p!
		ECHO #include "%%~nF.h" >> _o\_index.h
	)
)
