#ifndef ROGUE_HELPSTATE_H
#define ROGUE_HELPSTATE_H

#include "State.h"

class HelpState : public State {

 public:

	~HelpState();
	bool init();
	void draw();
	void handleInput(int input);
	void update();

};

#endif // ROGUE_HELPSTATE_H

