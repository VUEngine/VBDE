@echo off
v810-gcc -funroll-loops -finline-functions -O3 -I. %1.c -o %1.elf -mv810
v810-objcopy -O binary %1.elf %1.vb
v810-objdump -xd %1.elf > %1.S
REM ----- Pad ROM -----
padromvb.exe %1.VB 19
REM ----- Split for Chips -----
bintool /s %1.VB %1.1 %1.2

REM -x, --discard-all           Discard all local symbols
REM -X, --discard-locals        Discard temporary local symbols
REM --strip-local-absolute