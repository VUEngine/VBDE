CC=v810-gcc
LD=v810-gcc
AR=v810-ar
ARFLAGS=rcs
RM=rm

CFLAGS=-Wall -nodefaultlibs -mv810 -xc

SRC = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = $(SRC:.c=.o)

libgccvb.a: $(OBJ)
	$(AR) $(ARFLAGS) libgccvb.a $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) -rf $(OBJ) libgccvb.a
