#include "adjustmentScreen.h"

void adjustmentScreen()
{
	copymem((void*)CharSeg0, (void*)AdjustmentScreenTiles, 588);
	copymem((void*)BGMap(0), (void*)AdjustmentScreenMap, 2688);

	WA[31].head = WRLD_LON|WRLD_OVR;
	WA[31].w = 384;
	WA[31].h = 224;
	
	WA[30].head = WRLD_RON|WRLD_OVR;
	WA[30].w = 384;
	WA[30].h = 224;
	WA[30].my = 224;
	
	WA[29].head = WRLD_END;

	vbFXFadeIn(0);

	while(1) {
		if(buttonsPressed(K_ANY, true)) {
			break;
		}
	}

	vbFXFadeOut(0);
}