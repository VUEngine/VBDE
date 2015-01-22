#include <libgccvb.h>

#include <constants.h>
#include <functions.h>
#include <components.h>

int main()
{
    initSystem();

	precautionScreen();
	adjustmentScreen();
	languageSelectionScreen();

    gameLoop();

    return false;
}
