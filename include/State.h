#ifndef ROGUE_STATE_H
#define ROGUE_STATE_H

class State {

 public:

	virtual ~State();
	virtual void draw() =0;
	virtual void handleInput(int input) =0;
	virtual void update() =0;

};

#endif // ROGUE_STATE_H

