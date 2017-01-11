::ALLOW ACCESS TO VARIABLES SET BY "GET_TIMESTAMP_DIFF" FUNCTION
SETLOCAL ENABLEDELAYEDEXPANSION

::CONVERT ASSETS
IF EXIST %PROJECT_DIR%\assets\stages\ (

	::SWITCH TO IMAGES DIRECTORY
	PUSHD %PROJECT_DIR%\assets\stages\

	::FIND ALL TMX FILES
	FOR /r . %%F IN (*.tmx) DO (

	    ::SWITCH TO TMX FILE DIRECTORY
        PUSHD "%%~dpF"


            ::GET TIME DIFFERENCE BETWEEN TMX FILE AND C FILE
            SET TIMEDIFF=1
            IF EXIST "Definition\%%~nFDefinition.c" (
                CALL :GET_TIMESTAMP_DIFF "%%~nxF" "Definition\%%~nFDefinition.c" TIMEDIFF
            )

            ::CONVERT TMX FILE ONLY IF IT HAS CHANGED
            IF !TIMEDIFF! gtr 0 (
                ::CONVERT
                IF NOT EXIST "%%~dpF\Definition" MKDIR "%%~dpF\Definition"
                PUSHD "%%~dpF\Definition"
                "%VBDE%/system/tools/php/php.exe" "%VBDE%/system/tools/vuengine-tools/convert-tmx.php" "-f%%F" "-o%%~dpFDefinition\%%~nFDefinition.c" "-vtrue"
            )
	)
)

::SWITCH BACK TO PROJECT DIRECTORY
PUSHD %PROJECT_DIR%

::DO NOT PROCESS "GET_TIMESTAMP_DIFF" FUNCTION
GOTO :EOF



:GET_TIMESTAMP_DIFF
IF NOT EXIST "%~1" GOTO :EOF
IF NOT EXIST "%~2" GOTO :EOF
IF "%~3" == "" GOTO :EOF

FOR %%A IN (%~1) DO SET DATE1=%%~tA
FOR %%A IN (%~2) DO SET DATE2=%%~tA

SET /A TIMESTAMP1=%DATE1:~8,1%*60*24*31*12*10+%DATE1:~9,1%*60*24*31*12+%DATE1:~0,1%*60*24*31*10+%DATE1:~1,1%*60*24*31+%DATE1:~3,1%*60*24*10+%DATE1:~4,1%*60*24+%DATE1:~11,1%*60*10+%DATE1:~12,1%*60+%DATE1:~14,1%*10+%DATE1:~15,1%
SET /A TIMESTAMP2=%DATE2:~8,1%*60*24*31*12*10+%DATE2:~9,1%*60*24*31*12+%DATE2:~0,1%*60*24*31*10+%DATE2:~1,1%*60*24*31+%DATE2:~3,1%*60*24*10+%DATE2:~4,1%*60*24+%DATE2:~11,1%*60*10+%DATE2:~12,1%*60+%DATE2:~14,1%*10+%DATE2:~15,1%
IF "%DATE1:~17,1%" == "P" SET /A TIMESTAMP1=%TIMESTAMP1% +12*60
IF "%DATE2:~17,1%" == "P" SET /A TIMESTAMP2=%TIMESTAMP2% +12*60

SET /A %~3=%TIMESTAMP1% - %TIMESTAMP2%

GOTO :EOF