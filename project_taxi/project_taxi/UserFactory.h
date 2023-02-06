#pragma once
#include <iostream>
#include "User.h"
class UserFactory
{
public:
	virtual User* create() = 0;
};

