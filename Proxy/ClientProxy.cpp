#include "ClientProxy.h"

ClientProxy::~ClientProxy()
{
	delete iClientCon;
}

void ClientProxy::update(const Message & mess)
{
	iClientCon->send(mess);
}