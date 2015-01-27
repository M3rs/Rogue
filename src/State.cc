#include "State.h"

#include "TitleState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "HelpState.h"

State::~State() {
	// nothing in here
	// TODO: either implement this
	// OR figure out how to make this pure virtual ( = 0 ? )
}

State* State::getState(StateType type) {
	
	State* next = NULL;

	switch( type ) {
	case State::NONE:
		// NONE - why?
		break;
	case State::TITLE:
		next = new TitleState();
		break;
	case State::MENU:
		next = new MenuState();
		break;
	case State::HELP:
		next = new HelpState();
		break;
	case State::PLAY:
		next = new PlayState();
		break;
	}
	
	if(!next->init()) {
		delete next;
		next = NULL;
	} 

	return next;

}

