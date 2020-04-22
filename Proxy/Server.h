#ifndef SERVER_H
#define SERVER_H

#include "ClientProxy.h"
#include "Message.h"
#include "ChatLogger.h"
#include "ChatObserver.h"

class Server : public ChatObserver {
public:

	// Constructors
	Server() {};
	Server(const std::string &name, ClientProxy *clientProxy);

	virtual void update(const Message &mess);

	void attach(ClientProxy* clientProxy); // Attaches the clientProxy in the observers list (when he/she joins the chat)
	void attach(ChatObserver* chatLogger); // Attaches the chatLogger to the observers list (prints info to the log-file)
	void notify(Message &msg); // Notifies all observers of new messages
	void detach(ClientProxy* clientProxy); // Detaches the clientProxy from the observers list (when he/she leaves the chat)
	void addMessage(Message msg) { notify(msg); } // Message from server

private:
	list<ChatObserver*> observers;
	std::string name;

};
#endif