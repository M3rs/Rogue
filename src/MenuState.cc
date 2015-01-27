#include "MenuState.h"

#include "HelpState.h"
#include "PlayState.h"

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
			message.messageType = Message::NEXT;
			stateType = State::PLAY;
			break;
		case 'h':
			message.messageType = Message::NEXT;
			stateType = State::HELP;
			break;
		case 'q':
			// quit
			break;
		}


	}

}

void MenuState::update() {

	switch( message.messageType ) {
	case Message::QUIT:
		// do nothing ? or do I need to handle this?
		break;
	case Message::NEXT: 
		message.setNextState( State::getState(stateType) );
		break;
	default:
		break;
	}

}

