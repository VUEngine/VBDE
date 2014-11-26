@echo off
cd %1
C:\\vbde\\tools\\rom\\Pad_VB\\Pad_VB.exe %1/output.vb
start C:\vbde\tools\rom/FlashBoy_20101102/FlashBoy.exe
exit