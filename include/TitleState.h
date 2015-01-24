#ifndef ROGUE_TITLESTATE_H
#define ROGUE_TITLESTATE_H

#include "State.h"

class TitleState : public State {

 public:

	~TitleState();
	void draw();
	void handleInput(int input);
	void update();

};

#endif // ROGUE_TITLESTATE_H

