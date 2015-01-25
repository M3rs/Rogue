#include "GameEngine.h"

#include "TitleState.h"
#include "PlayState.h"

GameEngine::GameEngine() : running(true) {

}

GameEngine::~GameEngine() {

	// clean up the states
	for(auto& state : states) {
		delete state;
	}


		
	endwin(); // end curses mode

}

bool GameEngine::init() {

	srand(time(NULL)); // seed random number

	initscr(); // start curses mode
	//raw(); // ???

	keypad(stdscr, true); // don't echo getch
	curs_set(0); // hides cursor
	noecho();

	//start_color(); // setup colors
	if(!initColors()) {
		// report error
		reportError("init colors failed");
		return false;
	}

	return true;

}

void GameEngine::reportError(const char * errorMessage) {

	mvprintw(0,0,"-- ! Error: %s:", errorMessage);
	refresh();
	getch();

}

bool GameEngine::initColors() {
	
	start_color();

	if(!has_colors()) { return false; }
	init_pair(1, COLOR_WHITE, COLOR_GREEN);

	return true;


}

void GameEngine::run() {

	states.push_back(new TitleState());

	// player info
	Player player = Player();
	player.character = '@';
	player.color = 1;
	player.position = Point(10,10);
	
	//int input = 0;

	//int x = 10;
	//int y = 10;

	while(running) {

		draw();
		handleInput();
		update();
		/*
		// drawing code
		clear();

		player.draw();

		//attron(COLOR_PAIR(1));
		//mvaddch(y,x,'@');
		//attroff(COLOR_PAIR(1));

		refresh();

    // handle input
		input = getch();
    
		switch( input ) {
		case 'q':
			running = false;
			break;
	
		}

		player.handleInput( input );
        
    // update 
		player.update();
		*/

    }

}

void GameEngine::draw() {

	states.back()->draw();

}

void GameEngine::handleInput() {

	int input = getch();

	switch( input ) {
	case 'q':
		running = false;
		break;
	}
	
	states.back()->handleInput(input);


}

void GameEngine::update() {

	states.back()->update();

	switch( states.back()->message.messageType ) {
	case Message::NONE:
		// no message
		break;
	case Message::QUIT:
		running = false;
		break;
	case Message::NEXT:
		// push_back the state created (Message has State*, read from that)
		if( states.back()->message.nextState ) {
			// next state is valid, go to next state
			states.push_back( states.back()->message.nextState );

		} else {
			// nextState is NULL
			running = false;

		}

		break;
	}

}

