::ALLOW ACCESS TO VARIABLES SET BY "GET_TIMESTAMP_DIFF" FUNCTION
SETLOCAL ENABLEDELAYEDEXPANSION

::CONVERT ASSETS
IF EXIST %PROJECT_DIR%\assets\images\ (

	::SWITCH TO IMAGES DIRECTORY
	PUSHD %PROJECT_DIR%\assets\images\

	::FIND ALL GRIT FILES
	FOR /r . %%F IN (*.grit) DO (

	    ::SWITCH TO GRIT FILE DIRECTORY
        PUSHD %%~dpF

	    ::DETERMINE IF GRIT FILE BELONGS TO A SINGLE FILE OR TO WHOLE DIRECTORY
        SET SHARED=1
        FOR %%S IN (png bmp gif pcx jpg jpeg) DO (
            IF EXIST %%~dnpF.%%S (
                SET SHARED=0
                SET SINGLE_IMAGE=%%~dnpF.%%S
            )
        )

		::CONVERT IMAGE(S)
        IF !SHARED! gtr 0 (

            ::FIND ALL IMAGES IN CURRENT DIRECTORY
            SET IMAGES=
            SET IMAGES_CLEAN=
            SET TIMEDIFF=0
            FOR %%i IN (*.png *.bmp *.gif *.pcx *.jpg *.jpeg) DO (
                SET IMAGES=!IMAGES! "%%i"
                SET IMAGES_CLEAN=!IMAGES_CLEAN! "%%~nxi"

                ::GET TIME DIFFERENCE BETWEEN IMAGE AND C FILE
                IF EXIST "%%~dnpi.c" (
                    CALL :GET_TIMESTAMP_DIFF "%%i" "%%~dnpi.c" TIMEDIFF_CHECK
                    IF !TIMEDIFF_CHECK! gtr 0 (
                        SET TIMEDIFF=1
                    )
                ) ELSE (
                    SET TIMEDIFF=1
                )
            )

            ::CONVERT IMAGES ONLY IF AT LEAST ONE OF THEM HAS CHANGED
            IF !TIMEDIFF! gtr 0 (
                ::CONVERT
                %VBDE%\tools\graphics\grit-0.8.6\grit.exe !IMAGES! -O "%%~dnpF" -ff "%%F"

                ::ECHO
                ECHO Converted!IMAGES_CLEAN!
            )

        ) ELSE (

            ::GET TIME DIFFERENCE BETWEEN IMAGE AND C FILE
            SET TIMEDIFF=1
            IF EXIST "%%~dnpF.c" (
                CALL :GET_TIMESTAMP_DIFF "!SINGLE_IMAGE!" "%%~dnpF.c" TIMEDIFF
            )

            ::CONVERT IMAGE ONLY IF IT HAS CHANGED
            IF !TIMEDIFF! gtr 0 (
                ::CONVERT
                %VBDE%\tools\graphics\grit-0.8.6\grit.exe "%%~dnpF.png" -o "%%~dnpF" -ff "%%F"

                ::ECHO
                ECHO Converted "%%~nF.png"
            )
        )
	)
)

::SWITCH BACK TO PROJECT DIRECTORY
PUSHD %PROJECT_DIR%

::DO NOT PROCESS "GET_TIMESTAMP_DIFF" FUNCTION
GOTO :EOF



:GET_TIMESTAMP_DIFF
IF NOT EXIST %~1 GOTO :EOF
IF NOT EXIST %~2 GOTO :EOF
IF "%~3" == "" GOTO :EOF

FOR %%A IN (%~1) DO SET DATE1=%%~tA
FOR %%A IN (%~2) DO SET DATE2=%%~tA

SET /A TIMESTAMP1=%DATE1:~8,1%*60*24*31*12*10+%DATE1:~9,1%*60*24*31*12+%DATE1:~0,1%*60*24*31*10+%DATE1:~1,1%*60*24*31+%DATE1:~3,1%*60*24*10+%DATE1:~4,1%*60*24+%DATE1:~11,1%*60*10+%DATE1:~12,1%*60+%DATE1:~14,1%*10+%DATE1:~15,1%
SET /A TIMESTAMP2=%DATE2:~8,1%*60*24*31*12*10+%DATE2:~9,1%*60*24*31*12+%DATE2:~0,1%*60*24*31*10+%DATE2:~1,1%*60*24*31+%DATE2:~3,1%*60*24*10+%DATE2:~4,1%*60*24+%DATE2:~11,1%*60*10+%DATE2:~12,1%*60+%DATE2:~14,1%*10+%DATE2:~15,1%
IF "%DATE1:~17,1%" == "P" SET /A TIMESTAMP1=%TIMESTAMP1% +12*60
IF "%DATE2:~17,1%" == "P" SET /A TIMESTAMP2=%TIMESTAMP2% +12*60

SET /A %~3=%TIMESTAMP1% - %TIMESTAMP2%

GOTO :EOF