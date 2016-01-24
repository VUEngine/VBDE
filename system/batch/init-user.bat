::INIT USER FOLDER IF IT DOES NOT EXISTS
IF NOT EXIST "%VBDE%\cygwin\home\%USERNAME%\" (
    ::CREATE USER FOLDER
    MKDIR "%VBDE%\cygwin\home\%USERNAME%\" > nul
    ::COPY OVER FILES FROM SKELETON
    XCOPY "%VBDE%\cygwin\etc\skel\*" "%VBDE%\cygwin\home\%USERNAME%\*" > nul
    ::FIX PRIVILEGES
    %VBDE%\cygwin\bin\bash -l -c "mkpasswd -c >> /etc/passwd && mkgroup -c >> /etc/group"
)