#ifndef CHATLOGGER_H
#define CHATLOGGER_H

#include "ChatObserver.h"

class Server;  // Forward declaration

class ChatLogger : public ChatObserver {

public:
	ChatLogger(const string &aFileName, Server *aServ);
	virtual ~ChatLogger();

	virtual void update(const Message &mess);

private:
	string iFileName;
	ofstream iLogFile;
	Server *iServ;

};


#endif
