#include "grid.h"

u8 getNeighbourCount(int x, int y)
{
	return grid[y-1][x-1]
		+ grid[y-1][x]
		+ grid[y-1][x+1]
		+ grid[y][x-1]
		+ grid[y][x+1]
		+ grid[y+1][x-1]
		+ grid[y+1][x]
		+ grid[y+1][x+1];
}

u8 getNewCellState(int x, int y)
{
	u8 neighbourCount, returnValue;

	neighbourCount = getNeighbourCount(x, y);

	switch(neighbourCount) {
		case 2:
			returnValue = grid[y][x];
			break;

		case 3:
			returnValue = 1;
			break;

		default:
			returnValue = 0;
			break;
	}

	return returnValue;
}

void iterate()
{
	int x, y;
	u8 newGrid[HEIGHT][WIDTH];

	for(x = 0; x < WIDTH; x++) {
		for(y = 0; y < HEIGHT; y++) {
			newGrid[y][x] = getNewCellState(x, y);
		}
	}

	for(x = 0; x < WIDTH; x++) {
		for(y = 0; y < HEIGHT; y++) {
			grid[y][x] = newGrid[y][x];
		}
	}
}