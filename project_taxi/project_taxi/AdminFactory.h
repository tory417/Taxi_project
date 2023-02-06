#pragma once
#include <iostream>
#include "UserFactory.h"
#include "Admin.h"
class AdminFactory : public UserFactory
{
	Admin* admin;
public:
	User* create();
	
};

