#ifndef ROGUE_ENTITY_H
#define ROGUE_ENTITY_H

#include "ncurses.h"

#include "Point.h"

class Entity {
    
public:
    
	Point		position;
	Point		deltaPos;
	unsigned	character;
	int		color;
    
	void 		draw();
	void 		update();
    
};

#endif // ROGUE_ENTITY_H
