#ifndef _ASSETS_LANG_H
#define _ASSETS_LANG_H


enum {
     STR_LANGUAGE,
     STR_PRECAUTION,
};

#include "lang_en.h"
#include "lang_de.h"

enum {
     LANG_EN,
     LANG_DE,
};
char** languages[2] = {
	Lang_EN, 
	Lang_DE,
};


#endif