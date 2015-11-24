#include <constants.h>
#include <controller.h>
#include <mem.h>
#include <video.h>
#include <world.h>
#include <functions.h>
#include <languages.h>
#include "languageSelectionScreen.h"

extern u8 currentLanguage;

void languageSelectionScreen()
{
	u8 i = 0;
	int numLangs = 0;

    clearScreen();

	WA[31].head = WRLD_ON|WRLD_OVR;
	WA[31].w = 384;
	WA[31].h = 224;
	WA[30].head = WRLD_END;

    printString(0, 17, 10 + currentLanguage, ">");

	for(i = 0; __LANGUAGES[i]; i++) {
		printString(0, 18, 10 + i, (char *)__LANGUAGES[i][STR_LANGUAGE]);
		numLangs++;
	}

	vbFXFadeIn(0);

	while(1) {
		if(buttonsPressed(K_LU|K_RU, true) && (currentLanguage > 0)) {
            currentLanguage--;
            printString(0, 17, 10 + currentLanguage + 1, " ");
            printString(0, 17, 10 + currentLanguage, ">");
            vbWaitFrame(3);
		} else if(buttonsPressed(K_LD|K_RD, true) && (currentLanguage < (numLangs-1))) {
            currentLanguage++;
            printString(0, 17, 10 + currentLanguage - 1, " ");
            printString(0, 17, 10 + currentLanguage, ">");
            vbWaitFrame(3);
		} else if(buttonsPressed(K_STA|K_A, true)) {
			break;
		}
	}

	vbFXFadeOut(0);
}