#include <stdlib.h> 	// for rand(), srand()
#include <time.h> 	// for time()
#include <vector>	
#include <ncurses.h>	// for console manipulation, input, etc

#include "GameEngine.h"

//#include <typeinfo> // for debug

std::vector<unsigned> floor; // <chtype> : the "type" defined in ncurses

void drawBox(int x, int y, int w, int h);
void drawHashLine(int x1, int y1, int x2, int y2);

int main() {

	GameEngine game;
	
	if( game.init() ) {
		game.run();
	}

	return 0; // early return

	// TODO: Clean up this (delete), after moving relevant code
	// to places it needs to go. Mostly concerned about the
	// special characters from ncurses ( ACS_* )

	/*
	initscr(); // do this before ACS_ULCORNER, etc
	start_color(); // they are macros ? not CONST or whatever ??

	keypad(stdscr, true); // enables extra keys
	curs_set(0); // hides cursor
	*/

	// x = 10, y = 10, w = 6, h = 8
	// add floor
	floor.push_back(ACS_ULCORNER );
	floor.push_back(ACS_HLINE);
	floor.push_back(ACS_HLINE);
	floor.push_back('.');


	//srand(time(NULL));

	for(int i = 0; i < floor.size(); i++) {
		mvaddch(2, i + 1, floor[i] );
	}

	mvprintw(0,0,"hello");

	// Y, X, CHAR
	// ACS_ these are the extended ascii I need
	unsigned testC = ACS_ULCORNER;
	unsigned test2 = '.';
	mvaddch(3,3, testC); //ACS_ULCORNER);
	mvaddch(3,4, test2); //ACS_HLINE);

	drawBox(10,10,8,6);
	mvaddch(15,12,'.'); // random .
	drawHashLine(12,16,12,18);
	drawHashLine(12,18,18,18);

	drawHashLine(18,18, 18, 21);
	
	drawBox(16, 22, 8,12);
	mvaddch(22, 18, '.');

	getch();

	//endwin();

}

void drawBox(int x, int y, int w, int h) {

	for( int width = 0; width < w; width++) {
		for( int height = 0; height < h; height++) {
			
			if ( width == 0 && height == 0) {
				// upper left corner
				mvaddch(y+height, x+width, ACS_ULCORNER);
			} else if ( height == 0 && width == (w-1)) {
				// upper right corner
				mvaddch(y+height, x+width, ACS_URCORNER);
			} else if ( height == (h-1) && width == 0) {
				// lower left corner
				mvaddch(y+height, x+width, ACS_LLCORNER);
			} else if ( height == (h-1) && width == (w-1)) {
				// lower right corner
				mvaddch(y+height, x+width, ACS_LRCORNER);
			} else if (
				(width == 0 || width == (w-1)) &&
				(height > 0 && height < h)) {
				// verticle line
				mvaddch(y+height, x+width, ACS_VLINE);
			} else if (
				height == 0 || height == (h-1)) {
				// horizontal line
				mvaddch(y+height, x+width, ACS_HLINE);
			} else {
				// dot
				mvaddch(y+height,x+width,'.');
			}

		}
	}

}

void drawHashLine(int x1, int y1, int x2, int y2) {

	for(int x = 0; x <= (x2 - x1); x++) {
		for(int y = 0; y <= (y2-y1); y++) {
			mvaddch(y1+y, x1+x, '#');
		}
	}

}

