// TEST FOR WINDOWS in NCURSES

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main() {

	int parent_x, parent_y;
	int score_size = 3;

	initscr();
	noecho();
	curs_set(false);

	// get the max window dimensions
	getmaxyx(stdscr, parent_y, parent_x);

	// set up initial windows
	WINDOW *field = newwin(parent_y - score_size, parent_x, 0, 0);
	WINDOW *score = newwin(score_size, parent_x, parent_y - score_size, 0);

	if(!field) { 
		endwin();
		std::cout << "ERROR !field\n";
		return 1;
	} else if (!score) {
		endwin();
		std::cout << "ERROR !score\n";
		return 2;
	}

	// draw to the window
	mvwprintw(field, 0, 0, "Field");
	mvwprintw(score, 0, 0, "Score");

	// refresh each window
	wrefresh(field);
	wrefresh(score);

	//getch(); // wait for keypress
	sleep(5);

	// clean up
	delwin(field);
	delwin(score);

	endwin();

	std::cout << "Window size: " << parent_x << "," << parent_y << "\n";

}

