#include <constants.h>
#include <joypad.h>
#include <mem.h>
#include <video.h>
#include <world.h>
#include <input.h>
#include <text.h>
#include <lang.h>
#include "languageSelectionScreen.h"

extern u8 currentLanguage;
extern char** languages;

void languageSelectionScreen()
{
	u8 i = 0;

	setmem((void*)CharSeg0, 0x0000, 2048);
	setmem((void*)BGMap(0), 0x0000, 8192);

	WA[31].head = WRLD_ON|WRLD_OVR;
	WA[31].w = 384;
	WA[31].h = 224;
	WA[30].head = WRLD_END;

	for(i=0; i<sizeof(languages); i++) {
		if(i == currentLanguage) {
			printString(0, 17, 10+i, ">");
		}
		printString(0, 18, 10+i, &languages[i][STR_LANGUAGE]);
	}

	vbFXFadeIn(0);

	while(1) {
		if(buttonsPressed(K_ANY, false)) {
			break;
		}
	}

	vbFXFadeOut(0);
}