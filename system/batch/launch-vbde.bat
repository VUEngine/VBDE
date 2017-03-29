::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL "%~dp0\init.bat"

::LAUNCH VBDE EDITOR
IF EXIST "%VBDE%\editors\idea\" (

    ::DETERMINE SYSTEM ARCHITECTURE
    reg Query "HKLM\Hardware\Description\System\CentralProcessor\0" | find /i "x86" > NUL && set OS=32BIT || set OS=64BIT

    ::SWITCH TO IDEA DIRECTORY
    PUSHD "%VBDE%\editors\idea\bin\"

    ::LAUNCH RESP. IDEA VERSION FOR SYSTEM ARCHITECTURE
    IF %OS%==64BIT (
        START "" "idea64.exe"
    ) ELSE (
        START "" "idea.exe"
    )
) ELSE (
    ::SWITCH TO NPP DIRECTORY
    PUSHD "%VBDE%\editors\npp\"

    ::LAUNCH NPP
    START "" "notepad++.exe"
)
