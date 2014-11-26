void languageSelectionScreen()
{
	u8 i = 0;

	setmem((void*)CharSeg0, 0x0000, 2048);
	setmem((void*)BGMap(0), 0x0000, 8192);

	WA[31].head = WRLD_ON|WRLD_OVR;
	WA[31].w = 384;
	WA[31].h = 224;
	WA[30].head = WRLD_END;

	for(i=0; i<sizeof(LANG_LANGUAGE); i++) {
		if(i == currentLanguage) {
			printString(0, 17, 10+i, ">");
		}
		printString(0, 18, 10+i, LANG_LANGUAGE[i]);
	}

	vbFXFadeIn(0);

	while(1) {
		if(buttonsPressed(K_ANY, false)) {
			break;   
		}
	}

	vbFXFadeOut(0);
}