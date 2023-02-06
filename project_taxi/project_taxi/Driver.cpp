#include "Driver.h"

Driver::Driver(string name, string phone)
{
	this->name = name;
	this->phone = phone;
}

float Driver::getDriverRating()
{
	return 0.0f;
}

string Driver::getName()
{
	return name;
}

string Driver::getPhone()
{
	return phone;
}

void Driver::setName(string name)
{
	this->name = name;
}

void Driver::setPhone(string phone)
{
	this->phone = phone;
}

void Driver::changeProfit(float orderPrice)
{
	profit += orderPrice;
}

float Driver::calcRating(vector<int> marks)
{
	return 0.0f;
}
