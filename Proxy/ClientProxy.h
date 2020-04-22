#ifndef CLIENTPROXY_H
#define CLIENTPROXY_H

#include <list>
#include <string>

#include "Address.h"
#include "ClientConnection.h"
#include "ChatObserver.h"

class ClientProxy : public ChatObserver {
public:

	ClientProxy(std::string name, const Address &addr)
	{
		iClientCon = new HDclientConnection;
		iClientCon->connect(addr);
		myName = name;
	};

	virtual ~ClientProxy();

	virtual void update(const Message &mess);

	string getName() { return myName; }

private:

	HDclientConnection *iClientCon;
	string myName;

};


#endif