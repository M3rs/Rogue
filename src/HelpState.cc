#include "HelpState.h"

HelpState::~HelpState() {

}

bool HelpState::init() {

	return true;

}

void HelpState::draw() {

	clear();

	mvprintw(0,0,"-HelpState");
	mvprintw(1,0,"Press b to go back");

	refresh();

}

void HelpState::handleInput(int input) {

	switch( input ) {
	case 'b':
		message.messageType = Message::BACK;
		break;
	}

}

void HelpState::update() {

	// switch ?

}

