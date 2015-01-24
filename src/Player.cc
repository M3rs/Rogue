#include "Player.h"

void Player::handleInput(int input) {

deltaPos = Point(0,0);

switch( input ) {
	case KEY_LEFT:
		deltaPos.x = -1;
		break;	
	case KEY_RIGHT:
		deltaPos.x = 1;
		break;
	case KEY_UP:
		deltaPos.y = -1;
		break;
	case KEY_DOWN:
		deltaPos.y = 1;
		break;
}

}
