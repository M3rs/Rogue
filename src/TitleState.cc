#include "TitleState.h"

#include "MenuState.h"
#include "PlayState.h"

TitleState::~TitleState() {

}

bool TitleState::init() {

	// set up state, if it fails, return false and program quits
	return true;

}

void TitleState::draw() {

	int row, column;
	getmaxyx(stdscr, row, column);

	int thirdHeight = row / 3;
	//int halfHeight = row / 2; // was unused
	int halfWidth = column / 2;

	clear();

	// TODO: Draw a fancier ascii title
	mvprintw( thirdHeight, halfWidth, "/=+-------+=\\");
	mvprintw( thirdHeight + 1, halfWidth - 1, "|==| Rogue |==|");
	mvprintw( thirdHeight + 2, halfWidth, "\\=+-------+=/");

	mvprintw( thirdHeight + 4, halfWidth,"Press Enter to continue...");

	mvprintw(0,0,"-TitleState");
	//mvprintw(1,0,"x");

	refresh();

}

void TitleState::handleInput(int input) {

	switch(input) {

	case '\n': // ENTER KEY (KEY_ENTER is unreliable per ncurses):
		// next state
		message.messageType = Message::NEXT;
		break;
	}

}

void TitleState::update() {

	// not used 
	// (maybe if there is going to be "animation" on title)
	switch( message.messageType ) {
	case Message::NONE:
		// do nothing
		break;
	case Message::QUIT:
		// do nothing ?
		break;
	case Message::NEXT:
		
		State* next = new MenuState(); //new PlayState();

		if(next->init()) {
			message.nextState = next;
		} else {
			delete next;
			message.messageType = Message::QUIT; // failure to init
		} 

		break;
	
	}
		

}

