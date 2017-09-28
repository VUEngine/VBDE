#include <libgccvb.h>
#include "charset.h"

/** This demo, while functionally the same as demo 2, uses
 *  a group of objects instead of a bgmap.  This would be
 *  useful if you wanted to use objects for sprites, rather
 *  than devoting an entire bgmap to each one.
 */

/** This hideous array defines the numbers of chars we need
 *  to pull from the charset for each frame
 */
const BYTE ANIM[] = {0,1,2,3,4,5,8,9,13,14,0,1,2,3,6,7,10,11,15,16,0,1,2,3,6,5,12,9,17,18};

int main()
{
    int x=0;
    int y=0;
    int count=0;
    int frame=0;
    int cyclecount=0;
    int moving=0;
    int direction=1;
    int legs=1;
    HWORD pad;

    //Initialize registers
	vbSetColTable();
    vbDisplayOn();

    //Copy graphics to memory
    copymem((void*)CharSeg0, (void*)CHARSET, 22*16);

    //Setup object registers
    VIP_REGS[SPT3]=1024;
    VIP_REGS[SPT2]=1010;

    //Initialize the objects we will be using
    for (count=0; count<10; count++)
    {
	vbSetObject(1023-frame, OBJ_ON, x+(8*(count%2)), 0, y+(8*(count/2)), ANIM[count]);
    }
    count=0;

    //Setup worlds
    vbSetWorld(31, WRLD_ON | WRLD_OBJ, x, 0, y, 0, 0, 0, 0, 0);
    vbSetWorld(30, WRLD_END, 0, 0, 0, 0, 0, 0, 0, 0);

    //Set brightness registers
    vbDisplayShow();

    //Main game loop
    for(;;)
    {
	pad = vbReadPad();

	//Check each axis and update
	if (pad&K_LU) {
	    y--;
	    moving=1;
	}
	else if (pad&K_LD) {
	    y++;
	    moving=1;
	}

	if (pad&K_LL) {
	    x--;
	    moving=1;
	    direction=0;}
	else if (pad&K_LR) {
	    x++;
	    moving=1;
	    direction=1;
	}

	//Update the frame
	if (moving && cyclecount==0) {
	    if (legs)
	    {
		frame++;
		cyclecount=3;
		if (frame>1)
		    legs=0;
	    }
	    else
	    {
		frame--;
		cyclecount=3;
		if (frame<1)
		    legs=1;
	    }
	}
	moving=0;

	//Update the group of objects based on current variable values
	if (direction)
	{
	    for (count=0; count<10; count++)
	    {
		vbSetObject(1023-count, OBJ_ON, x+(8*(count%2)), 0, y+(8*(count/2)), ANIM[count+(frame*10)]);
	    }
	}
	else
	{
	    for (count=9; count>=0; count--)
	    {
		vbSetObject(1023-count, OBJ_ON | OBJ_HFLIP, (x+8)+(-8*(count%2)), 0, y+(8*(count/2)), ANIM[count+(frame*10)]);
	    }
	}

	//Cyclecount slows the animation down a bit
	if (cyclecount>0) cyclecount--;

	//Wait for the end of the frame
	vbWaitFrame(0);
    }
    return 0;
}
