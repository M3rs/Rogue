#include "PlayState.h"

PlayState::~PlayState() {

}

bool PlayState::init() {

	// set up PlayState, if fails, return false (causes game to quit);
	return true;
}

void PlayState::draw() {

	clear();

	mvprintw(0,0,"Play State!!");

	refresh();

}

void PlayState::handleInput(int input) {

}

void PlayState::update() {

}

