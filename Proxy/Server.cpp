#include "Server.h"

Server::Server(const string &name, ClientProxy *pServ)
	:ChatObserver(name)
{
	attach(pServ);
	this->name = name;
}

void Server::update(const Message &mess) {
	
	if (mess.getSender() != getName())
		cout << mess.getSender() << "> " << mess.getMessage();

}

void Server::attach(ClientProxy *clientProxy)
{
	observers.push_back(clientProxy);
	notify(Message("Server", clientProxy->getName() + " has joined the chat"));
}


void Server::attach(ChatObserver* obs)
{
	observers.push_back(obs);
	notify(Message("Server", obs->getName() + " has joined the chat"));
}

void Server::notify(Message& msg)
{
	for (ChatObserver* observer : observers)
		observer->update(msg);
}

void Server::detach(ClientProxy* clientProxy)
{
	list<ChatObserver*>::iterator it;
	for (it = observers.begin(); it != observers.end(); ++it)
		if ((*it) == clientProxy) {
			notify(Message("Server", clientProxy->getName() + " has left the chat"));
			observers.erase(it);
			break;
		}
}