#include <functions.h>
#include <components.h>

int main()
{
    initSystem();

	precautionScreen();
	adjustmentScreen();
	languageSelectionScreen();

    gameLoop();

    return 0;
}