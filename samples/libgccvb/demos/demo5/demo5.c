#include <libgccvb.h>
#include "font.h"
#include "message.h"

/** Moving back to bgmaps, this demo loads a predefined
 *  bgmap into memory one byte at a time with a delay, for
 *  an old rpg textbox kind of look (at least that's what
 *  I was going for.) This is at least good for showing how
 *  BGMaps actually work in memory. I originally thought
 *  that I'd use this in my compo entry somewhere, but then
 *  I decided to go in a different direction...
 */

/** Hey look, I finally started using constants...  (Kids,
 *  these make your program a lot more readable and easier
 *  to edit!)
 */
//Each reference is 2 bytes (took me a while to figure this out :P)
#define REFSIZE 2

//The length of each line, so we know when to quit
const char lineLength[] = {23,18,33,15};

int main()
{
    //Define a bunch of variables on one line
    int lineNum, charNum, count;
    //We want to copy bytes to the BGMap
    BYTE* BGMLOC = (void*)BGMap(0);

	vbSetColTable();
    vbDisplayOn();

    //Copy the charset
    copymem((void*)CharSeg0, (void*)FONT, 16*27);

    vbSetWorld(31, WRLD_ON | WRLD_BGMAP, 0, 0, 0, 0, 0, 0, 512, 512);
    vbSetWorld(30, WRLD_END, 0, 0, 0, 0, 0, 0, 0, 0);

    vbDisplayShow();

    //The following code should copy each line of text to memory without
    //copying the entire BGMap.

    //For each line
    for (lineNum=0; lineNum<4; lineNum++)
    {
	//For each character in the line
	for (charNum=0; charNum<lineLength[lineNum]; charNum++)
	{
	    //For each byte in the character
	    for(count=0; count<REFSIZE; count++)
	    {
		BGMLOC[(lineNum*64*3*REFSIZE)+(charNum*REFSIZE)+count] = MESSAGE[(lineNum*64*REFSIZE)+(charNum*REFSIZE)+count];
		vbWaitFrame(1);
	    }
	}
    }

    //We don't want to reach the end...
    for(;;);

    return 0;
}
