#ifndef ROGUE_PLAYSTATE_H
#define ROGUE_PLAYSTATE_H

#include "State.h"

class PlayState : public State {

 public:

	~PlayState();

	void draw();
	void handleInput(int input);
	void update();

};

#endif // ROGUE_PLAYSTATE_H

