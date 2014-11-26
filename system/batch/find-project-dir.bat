SET PROJECT_DIR=%1
IF EXIST %PROJECT_DIR%/../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..
) ELSE IF EXIST %PROJECT_DIR%/../../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..\..
) ELSE IF EXIST %PROJECT_DIR%/../../../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..\..\..
) ELSE IF EXIST %PROJECT_DIR%/../../../../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..
) ELSE IF EXIST %PROJECT_DIR%/../../../../../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..
) ELSE IF EXIST %PROJECT_DIR%/../../../../../../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..\..
) ELSE IF EXIST %PROJECT_DIR%/../../../../../../../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..\..\..
) ELSE IF EXIST %PROJECT_DIR%/../../../../../../../../header (
	SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..\..\..\..
)