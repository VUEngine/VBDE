output.vb: output.o

output.o: $(SOURCE).c
	v810-gcc -o output.o $(SOURCE).c -Wall -nodefaultlibs -mv810 -T$(VBDE)/cygwin/opt/gccvb/v810/lib/vb.ld -I$(VBDE)/libs/libgccvb -B$(VBDE)/cygwin/opt/gccvb/v810/lib/
	v810-objcopy -S -O binary output.o output.vb
