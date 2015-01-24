#ifndef ROGUE_DUNGEONMAKER_H
#define ROGUE_DUNGEONMAKER_H

class DungeonMaker {

 public:

	void initArray();

 private:

	int MAX_WIDTH;
	int MAX_HEIGHT;

	int dungeon[10][10];

};

#endif // ROGUE_DUNGEONMAKER_H

