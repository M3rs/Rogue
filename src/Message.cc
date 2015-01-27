#include "Message.h"

#include "State.h"

Message::Message() : messageType(Message::NONE) {

}

void Message::setNextState(State* next) {

	if(next) {
		nextState = next;
	} else {
		messageType = Message::QUIT;
	}

}

