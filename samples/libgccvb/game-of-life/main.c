/***************************/
/*     GAME OF LIFE VB     */
/***************************/

#include <libgccvb.h>
#include "grid.h"
#include "logic.h"
#include "rendering.h"

int main()
{
    setup();

	while(1) {
		iterate();
		render();
		vbWaitFrame(5);
	}

	return 0;
}