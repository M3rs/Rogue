#include <iostream>
#include <ncurses.h>

int main() {

	initscr();

	keypad(stdscr, true);
	
	int x;

	while(x != 'q') {
		x = getch();

		clear();
		mvprintw(0,0, "key: %d",  x);

		mvprintw(3,0, "KEY_ENTER: %d", KEY_ENTER);
		mvprintw(4,0, "New line: %d", '\n');

		refresh();

	}

	endwin();

}
