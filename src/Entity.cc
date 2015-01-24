#include "Entity.h"

void Entity::draw() {

	attron(COLOR_PAIR( color ));
	mvaddch(position.y, position.x, character);
	attroff(COLOR_PAIR( color ));	

}

void Entity::update() {

	// update logic here
	//position = position + deltaPos;
	position.x += deltaPos.x;
	position.y += deltaPos.y;

}

