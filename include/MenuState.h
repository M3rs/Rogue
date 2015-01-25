#ifndef ROGUE_MENUSTATE_H
#define ROGUE_MENUSTATE_H

#include "State.h"

#include <map>
#include <string>

class MenuState : public State {

 public:

	 ~MenuState();

	 bool init();
	 void draw();
	 void handleInput(int input);
	 void update();

 private:

	 std::map<int, std::string> options;
	 //bool renderChanged // TODO : so draw knows to draw (maybe?)

};

#endif // ROGUE_MENUSTATE_H

