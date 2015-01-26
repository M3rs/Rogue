#ifndef ROGUE_MESSAGE_H
#define ROGUE_MESSAGE_H

// foward declaration
class State;


class Message {

 public:

	Message();

	enum MessageType { NONE, QUIT, NEXT, BACK };

	MessageType messageType;

	State* nextState;

};

#endif // ROGUE_MESSAGE_H

