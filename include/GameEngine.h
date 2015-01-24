#ifndef ROGUE_GAMEENGINE_H
#define ROGUE_GAMEENGINE_H

// includes
#include <stdlib.h>		// rand(), srand()
#include <time.h>			// time()
#include <vector>

#include <ncurses.h>	// console manipulation, input, etc

#include "Point.h"
#include "Player.h"

// foward decs
class State;

class GameEngine {

 public:
	
   GameEngine();
	~GameEngine();

	bool init();
	void run();

 private:

	std::vector<State*> states;
	bool running;
 
	void reportError(const char * errorMessage);
	bool initColors();

	//void draw();
	//void handleInput();
	//void update();

};

#endif // ROGUE_GAMEENGINE_H

