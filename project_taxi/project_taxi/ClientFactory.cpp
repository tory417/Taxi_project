#include "ClientFactory.h"

User* ClientFactory::create()
{
	
	client = new Client();
	return client;
}
