SET PROJECT_DIR=%1

IF EXIST %PROJECT_DIR%/../header SET res=1
IF EXIST %PROJECT_DIR%/../makefile SET res=1
IF DEFINED res (
	SET PROJECT_DIR=%PROJECT_DIR%\..
) ELSE (
    IF EXIST %PROJECT_DIR%/../../header SET res=1
    IF EXIST %PROJECT_DIR%/../../makefile SET res=1
    IF DEFINED res (
        SET PROJECT_DIR=%PROJECT_DIR%\..\..
    ) ELSE (
        IF EXIST %PROJECT_DIR%/../../../header SET res=1
        IF EXIST %PROJECT_DIR%/../../../makefile SET res=1
        IF DEFINED res (
            SET PROJECT_DIR=%PROJECT_DIR%\..\..\..
        ) ELSE (
            IF EXIST %PROJECT_DIR%/../../../../header SET res=1
            IF EXIST %PROJECT_DIR%/../../../../makefile SET res=1
            IF DEFINED res (
                SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..
            ) ELSE (
                IF EXIST %PROJECT_DIR%/../../../../../header SET res=1
                IF EXIST %PROJECT_DIR%/../../../../../makefile SET res=1
                IF DEFINED res (
                    SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..
                ) ELSE (
                    IF EXIST %PROJECT_DIR%/../../../../../../header SET res=1
                    IF EXIST %PROJECT_DIR%/../../../../../../makefile SET res=1
                    IF DEFINED res (
                        SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..\..
                    ) ELSE (
                        IF EXIST %PROJECT_DIR%/../../../../../../../header SET res=1
                        IF EXIST %PROJECT_DIR%/../../../../../../../makefile SET res=1
                        IF DEFINED res (
                            SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..\..\..
                        ) ELSE (
                            IF EXIST %PROJECT_DIR%/../../../../../../../../header SET res=1
                            IF EXIST %PROJECT_DIR%/../../../../../../../../makefile SET res=1
                            IF DEFINED res (
                                SET PROJECT_DIR=%PROJECT_DIR%\..\..\..\..\..\..\..\..
                            )
                        )
                    )
                )
            )
        )
    )
)