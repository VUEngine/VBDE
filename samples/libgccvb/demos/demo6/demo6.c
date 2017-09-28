#include <libgccvb.h>
#include "font.h"

/** This is a fun one...  It uses a timer interrupt to
 *  display a realtime clock.  The digits are displayed
 *  with objects again (I could've used a bgmap, but I
 *  like objects.)  The clock just counts up time elapsed
 *  since start in seconds, minutes, and hours... (So I
 *  guess it's not much to look at, but it was at least
 *  fun to write...) Keep in mind that a timer interrupt
 *  like this one is useful in games where you need to
 *  keep track of something that happens independent of
 *  how fast the rest of the game loop runs (like music.)
 */

//Define our time variables globally
BYTE seconds;
BYTE minutes;
BYTE hours;

//Function prototypes
void update_clock(void);
void tim_handler(void);
extern u32 timVector;

int main(void)
{
    //Initialize variables
    seconds=0;
    minutes=0;
    hours=0;
    HWORD i;

    //Set up display registers
	vbSetColTable();
    vbDisplayOn();

    //Copy the font to character memory
    copymem((void*)CharSeg0, (void*)FONT, 16*11);

    //We will be using 8 objects to display the time
    VIP_REGS[SPT3]=1023;
    VIP_REGS[SPT2]=1015;

    //Set up clock display
    for (i=1023; i>1015; i--)
    {
	vbSetObject(i, OBJ_ON, (1023-i)*8, 0, 0, 0);
	if ((i==1021) || (i==1018))
	    OBJ_CSET(i,10);
    }

    //We will only need one object world
    vbSetWorld(31, WRLD_ON | WRLD_OBJ, 0, 0, 0, 0, 0, 0, 0, 0);
    vbSetWorld(30, WRLD_END, 0, 0, 0, 0, 0, 0, 0, 0);

    //Turn the display on
    vbDisplayShow();

    //Enable interrupts
    timVector = (u32)(tim_handler);
    INT_ENABLE;

    //Setup timer interrupt for a 1 second interval
    //Set the period of one timer "tick"
    timer_freq(TIMER_100US);
    //Set how many "ticks" before the interrupt is triggered
    timer_set(TIME_MS(1000));
    //Clear the interrupt status to get it ready to start
    timer_clearstat();
    //Enable the interrupt
    timer_int(1);
    //Start the timer
    timer_enable(1);

    for(;;)
    {
	//Update objects continuously (Just to give the main loop something to do)
	//Hours
	OBJ_CSET(1023,hours/10);
	OBJ_CSET(1022,hours%10);
	//Minutes
	OBJ_CSET(1020,minutes/10);
	OBJ_CSET(1019,minutes%10);
	//Seconds
	OBJ_CSET(1017,seconds/10);
	OBJ_CSET(1016,seconds%10);
    }

    return 0;
}

//This is called on the timer interrupt to update the time
void update_clock(void)
{
    seconds++;
    if (seconds>59)
    {
	seconds=0;
	minutes++;
	if (minutes>59)
	{
	    minutes=0;
	    hours++;
	    if (hours>23)
	        hours=0;
	}
    }
}

//Timer interrupt vector
void tim_handler(void)
{
    //Disable the interrupt and clear it while we do this
    timer_int(0);
    timer_clearstat();

    update_clock();

    //Re-enable the interrupt
    timer_int(1);
}
