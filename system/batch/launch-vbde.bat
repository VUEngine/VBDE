::SET ECHO OFF
@echo off

::SCRIPT INITIALIZATION
CALL "%~dp0\init.bat"

::LAUNCH VBDE EDITOR
IF EXIST "%VBDE%\editors\idea\" (
    ::SWITCH TO IDEA DIRECTORY
    PUSHD "%VBDE%\editors\idea\bin\"

    ::DETERMINE SYSTEM ARCHITECTURE
    SET "ARCH=x64"
    IF NOT EXIST "%SystemRoot%\SysWOW64\cmd.exe" (
        IF NOT DEFINED PROCESSOR_ARCHITEW6432 SET "ARCH=x86"
    )

    ::LAUNCH RESP. IDEA VERSION FOR SYSTEM ARCHITECTURE
    IF "%ARCH%"=="x64" (
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
