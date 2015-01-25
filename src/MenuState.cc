#include "MenuState.h"

MenuState::~MenuState() {

}

bool MenuState::init() {

	// menu set up here
	options['e'] = "Embark on your adventure";
	options['h'] = "Help";
	options['q'] = "Quit";

	return true;
}

void MenuState::draw() {

	int row, column;
	getmaxyx(stdscr, row, column);

	clear();

	// draw menu here
	int offset = 0;
	for( auto iter = options.begin(); iter != options.end(); iter++) {
		mvprintw((row / 2) + offset++, 
						((column / 2) - ((iter->second).length() / 2)),
					 	"%c. %s", iter->first, iter->second.c_str());
	}

	refresh();

}

void MenuState::handleInput(int input) {

	if( options.count(input) ) { // option found

		switch( input ) {
		case 'e':
			// go to play state
			break;
		case 'q':
			// quit
			break;
		}


	}

}

void MenuState::update() {

	switch( message.messageType ) {
	case Message::NONE:
		// do nothing
		break;
	case Message::QUIT:
		// do nothing ?
		break;
	case Message::NEXT:
		// set up next state depending on message?
		break;

	}

}

