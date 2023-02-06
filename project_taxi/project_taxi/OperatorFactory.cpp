#include "OperatorFactory.h"

User* OperatorFactory::create()
{
	
	oper = new Operator();
	return oper;
}
