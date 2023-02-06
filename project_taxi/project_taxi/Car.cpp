#include "Car.h"

Car::Car(string number, string color, string model, string type)
{
	this->number = number;
	this->color = color;
	this->model = model;
	this->type = type;
}

Car::Car(Driver driver) :Car(number, color, model, type)
{
	this->driver = driver;
}

string Car::getNum()
{
	return number;
}

string Car::getColor()
{
	return color;
}

string Car::getModel()
{
	return model;
}

string Car::getDriver()
{
	string buf = "";
	buf += driver.getName();
	buf += driver.getPhone();
	return buf;
}

string Car::getType()
{
	return type;
}

void Car::setNum(string num)
{
	this->number = num;
}

void Car::setColor(string color)
{
	this->color = color;
}

void Car::setModel(string model)
{
	this->model = model;
}

void Car::setType(string type)
{
	this->type = type;
}


void Car::setDriver(Driver driver)
{
	this->driver.setName(driver.getName());
	this->driver.setPhone(driver.getPhone());

}
