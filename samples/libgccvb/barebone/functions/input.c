#include <libgccvb.h>
#include <constants.h>
#include "input.h"

extern u16 lastPressedButtons;

u8 buttonsPressed(u16 buttons, u8 forceRelease)
{
	if(!(vbReadPad()&buttons)) lastPressedButtons = 0;

	if( (vbReadPad()&buttons) && ((!forceRelease) || (lastPressedButtons != vbReadPad()))) {
		lastPressedButtons = vbReadPad();
		return true;
	} else {
		return false;
	}
}