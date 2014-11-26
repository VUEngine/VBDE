#include <libgccvb.h>
#include "charset.h"

/** This was my first foray into objects.  It's pretty crude
 *  but it does demonstrate the advantages that objects have
 *  over bgmaps.  It scrolls 20 red squares across the screen
 *  at varying speeds.  It makes some pretty neat patterns.
 */

//This defines a structure to make it easier to define the position of each block
typedef struct
{
    int x;
    int y;
    int xVel;
} block;

block stuff[20];

int main()
{
    int i;

    //Copy charset to memory
    //(Even though it's so small you could almost generate it procedurally)
    copymem((void*)CharSeg0, (void*)CHARSET, 16*10);

    vbDisplayOn();

    //Setup a single object world
    vbSetWorld(31, WRLD_ON | WRLD_OBJ, 0, 0, 0, 0, 0, 0, 382, 224);
    vbSetWorld(30, WRLD_END, 0, 0, 0, 0, 0, 0, 0, 0);

    //Setup object registers so world 1 will display 24 objects
    VIP_REGS[SPT3] = 1024;
    VIP_REGS[SPT2] = 1000;

    //Initialize the array of blocks
    for (i=0; i<20; i++)
    {
	stuff[i].x = -7;
	stuff[i].y = i*10;
	stuff[i].xVel = i;
    }

    vbDisplayShow();
    
    for(;;)
    {
	for (i=0; i<20; i++)
	{
	    //Update each block in the array
	    stuff[i].x += stuff[i].xVel;
	    if (stuff[i].x > 383)
	    	stuff[i].x = -7;
		stuff[i].y = i*10;
		stuff[i].xVel = i;
	    //Update the object for that block
	    vbSetObject(1024-i, OBJ_ON, stuff[i].x, 0, stuff[i].y, 8);
	}

	//Wait for the end of the frame
	vbWaitFrame(0);
    }
    return 0;
}
