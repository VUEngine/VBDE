#include <libgccvb.h>
#include "grid.h"
extern BYTE TilesTiles[];

void setup()
{
	vbSetColTable();
	vbDisplayOn();

	copymem((void*)CharSeg0, (void*)TilesTiles, 2*16);

    WA[31].head = WRLD_ON;
	WA[31].w = 384;
	WA[31].h = 224;

	WA[30].head = WRLD_ON|1;
	WA[30].w = 384;
	WA[30].h = 224;
	WA[30].gx = 4;
	WA[30].gy = 0;

	WA[29].head = WRLD_ON|2;
	WA[29].w = 384;
	WA[29].h = 224;
	WA[29].gx = 0;
	WA[29].gy = 4;

	WA[28].head = WRLD_ON|3;
	WA[28].w = 384;
	WA[28].h = 224;
	WA[28].gx = 4;
	WA[28].gy = 4;

	WA[27].head = WRLD_END;

	vbDisplayShow();
}

void render()
{
	int x, y;

	for(x = 0; x < WIDTH; x++)
	{
		for(y = 0; y < HEIGHT; y++)
		{
			BGMM[0x1000*((x%2) + 2*(y%2))
				+ (x/2)
				+ (64*(y/2))] = grid[y][x];
		}
	}
}
