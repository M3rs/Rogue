#include "GameEngine.h"

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

	PlayState *  play = new PlayState();

	delete play;

	Player player = Player();
	player.character = '@';
	player.color = 1;
	player.position = Point(10,10);
	int input = 0;

	int x = 10;
	int y = 10;

	while(running) {

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

    }

}

