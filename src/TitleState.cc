#include "TitleState.h"

TitleState::~TitleState() {

}

void TitleState::draw() {

	clear();

	mvprintw(0,0,"Main Menu");
	mvprintw(5,0,"Press Enter to continue...");

	refresh();

}

void TitleState::handleInput(int input) {

	switch(input) {

		case KEY_ENTER:
			// next state
			break;
	}

}

void TitleState::update() {

	// not used 
	// (maybe if there is going to be "animation" on title)

}

