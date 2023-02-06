#pragma once
#include <iostream>
#include "UserFactory.h"
#include "Client.h"
class ClientFactory : public UserFactory
{
	Client* client;
public:
	User* create();
};

