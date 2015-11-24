#include <libgccvb.h>
#include "grid.h"
extern BYTE TilesTiles[];

void setup()
{
	vbDisplayOn();

	copymem((void*)CharSeg0, (void*)TilesTiles, 2*16);

	WA[31].head = WRLD_ON;
	WA[31].w = 384;
	WA[31].h = 224;
	WA[30].head = WRLD_END;

	vbDisplayShow();
}

void render()
{
	int x, y;

	for(x = 0; x < WIDTH; x++) {
		for(y = 0; y < HEIGHT; y++) {
			BGMM[x+64*y] = grid[y][x];
		}
	}
}