#include "AdminFactory.h"

User* AdminFactory::create()
{
	
	admin = new Admin();
	return admin;
}
