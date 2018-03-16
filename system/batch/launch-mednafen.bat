:: launch mednafen
START "" "%VBDE%\tools\emus\mednafen-0.9.48-win32\mednafen.exe" "%PROJECT_DIR%\build\output.vb"

:: bring emulator window to front and center it
%VBDE%\system\tools\nircmd\nircmd.exe win activate center title "output"
