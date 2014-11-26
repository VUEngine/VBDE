#include <libgccvb.h>

#include "constants.h"
#include "assets/assets.h"
#include "functions/functions.h"
#include "components/components.h"

int main()
{
    initSystem();

	precautionScreen();
	adjustmentScreen();
	languageSelectionScreen();

    gameLoop();

    return 0;
}