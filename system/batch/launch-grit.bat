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
		%VBDE%\tools\graphics\grit-0.8.6\grit.exe %%F -o _o\%%~nF.s  -ftc -gB2 -gu8 -m -mB16:p2hv_i11 -mLs -mu8 -mRtf -p!
		ECHO #include "%%~nF.h" >> _o\_index.h
	)
)

::SWITCH TO ASSETS DIRECTORY
PUSHD %PROJECT_DIR%
