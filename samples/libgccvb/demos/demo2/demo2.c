#include <libgccvb.h>
#include "charset.h"
#include "charmap.h"

/** This demo expands upon the last one by using a bgmap
 *  to do a simple walking animation. This is one example
 *  of how to handle animation, but note that the length
 *  of each frame may vary because we're using vbWaitFrame
 *  instead of a proper interrupt.
 */

int main()
{
    //Program variables
    int x=0;
    int y=0;
    //Let's use bytes to save some precious memory
    BYTE frame=0;
    BYTE cyclecount=0;
    //We don't have booleans, so a byte will do
    BYTE moving=0;
    BYTE direction=1;
    BYTE legs=1;
    //And a 16-bit variable to store the gamepad values
    HWORD pad;

    //Initialize registers
	vbSetColTable();
    vbDisplayOn();

    //Copy graphics to memorys
    copymem((void*)CharSeg0, (void*)CHARSET, 22*16);
    copymem((void*)BGMap(0), (void*)CHARMAP, 262*16);

    //Setup worlds
    vbSetWorld(31, WRLD_ON | WRLD_BGMAP, x, 0, y, frame*16, 0, 0, 16, 40);
    vbSetWorld(30, WRLD_END, 0, 0, 0, 0, 0, 0, 0, 0);

    //Set brightness registers
    vbDisplayShow();

    //Main game loop
    while(1)
    {
	//Store the pad so we don't have to read it multiple times
	pad = vbReadPad();

	//Read each axis and update the character
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
	    direction=0;
	}
	else if (pad&K_LR) {
	    x++;
	    moving=1;
	    direction=1;
	}

	//Debug function: uncomment this block to allow you to
	//change the frame number with the right d-pad
	/*if ((pad&K_RU) && (frame<2) && (cyclecount==0)) {
	    frame++;
	    cyclecount=3;
	}
	else if ((pad&K_RD) && (frame>0) && (cyclecount==0)) {
	    frame--;
	    cyclecount=3;
	}*/

	//Update the frame number
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

	//Update the world using new values
	if (direction)
	    vbSetWorld(31, WRLD_ON | WRLD_BGMAP, x, 0, y, frame*16, 0, 0, 15, 40);
	else
	    vbSetWorld(31, WRLD_ON | WRLD_BGMAP, x, 0, y, (frame*16)+48, 0, 0, 15, 40);

	//Cyclecount slows the animation down a bit
	if (cyclecount>0) cyclecount--;

	//Wait for the end of the frame (This slows the whole program a bit)
	vbWaitFrame(0);
    }
    return 0;
}
