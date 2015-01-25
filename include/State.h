#ifndef ROGUE_STATE_H
#define ROGUE_STATE_H

#include "ncurses.h"

#include "Message.h"

class State {

 public:

	enum StateType { NONE, TITLE, MENU, PLAY };

	virtual ~State();
	virtual bool init() =0;
	virtual void draw() =0;
	virtual void handleInput(int input) =0;
	virtual void update() =0;

	StateType stateType;
	Message message;

};

#endif // ROGUE_STATE_H

