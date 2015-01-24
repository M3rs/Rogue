#ifndef ROGUE_MESSAGE_H
#define ROGUE_MESSAGE_H

class Message {

 public:

	Message();

	enum MessageType { NONE, QUIT, NEXT };

	MessageType messageType;

};

#endif // ROGUE_MESSAGE_H

