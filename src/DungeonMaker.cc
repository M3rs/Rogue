#include "DungeonMaker.h"

void DungeonMaker::initArray() {

	for( int y = 0; y < MAX_HEIGHT; y++) {
		for( int x = 0; x < MAX_WIDTH; x++) {
			dungeon[x][y] = ' ';
		}
	}

}
