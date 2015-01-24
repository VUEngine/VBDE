#ifndef __MEM_H
#define __MEM_H

#include "types.h"


extern u8* const	EXPANSION;				// Expansion bus area
extern u8* const	WORKRAM;				// Scratchpad RAM; USE WITH CAUTION!
									// (In fact, just leave it alone!)
extern u16* const	SAVERAM;				// Cartridge's Battery-backed SRAM

/***** Ancillary Functions *****/

// Copy a block of data from one area in memory to another.
void copymem (u8* dest, const u8* src, u16 num);

// Set each byte in a block of data to a given value.
void setmem (u8* dest, u8 src, u16 num);

/*	Copy a block of data from one area in memory to another,
adding a given value to each byte, first.	*/
void addmem (u8* dest, const u8* src, u16 num, u8 offset);

#endif
