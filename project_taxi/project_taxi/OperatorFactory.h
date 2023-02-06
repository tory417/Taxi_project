#pragma once
#include <iostream>
#include "UserFactory.h"
#include "Operator.h"
class OperatorFactory : public UserFactory
{
	Operator* oper;
public:
	User* create();
};

