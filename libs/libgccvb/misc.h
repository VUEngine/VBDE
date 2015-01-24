#ifndef __MISC_H
#define __MISC_H

#include "types.h"
#include "mem.h"
#include "video.h"


#define tabsize 4 //horizontal tab size in chars
#define MISC_STATIC

extern const char nums[16];


MISC_STATIC char *itoa(u32 num, u8 base, u8 digits);

void cls();

void vbTextOut(u16 bgmap, u16 col, u16 row, char *t_string);

void vbPrint(u8 bgmap, u16 x, u16 y, char *t_string, u16 bplt);


#endif
