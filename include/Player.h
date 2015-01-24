#ifndef ROGUE_PLAYER_H
#define ROGUE_PLAYER_H

#include "Entity.h"

class Player : public Entity { // : public Entity

 public:
    
	void 	handleInput(int input);
    
};

#endif // ROGUE_PLAYER_H
