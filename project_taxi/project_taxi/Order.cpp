#include "Order.h"

Order::Order(int number, string coordA, string coordB, float distance, string name, string phone)
{
	this->number = number;
	this->coordA = coordA;
	this->coordB = coordB;
	this->distance = distance;
	this->nameClient = name;
	this->phoneClient = phone;
}

void Order::setCar(Car car)
{
	this->car.setDriver(car.driver);
	this->car.setColor(car.getColor());
	this->car.setModel(car.getModel());
	this->car.setNum(car.getNum());
	this->car.setType(car.getType());
}

float Order::getOrderPrice()
{
	return calcPrice();
}

int Order::getOrderNumber()
{
	return number;
}

string Order::getTime()
{
	time_t t = time(nullptr);
	tm* now = localtime(&t);

	char buffer[128];
	strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
	//realTime = buffer;
	return buffer;
}

//string Order::getRealTime()
//{
//	return realTime;
//}

string Order::getA()
{
	return coordA;
}

string Order::getB()
{
	return coordB;
}

float Order::getDistance()
{
	return distance;
}

string Order::getNameClient()
{
	return nameClient;
}

string Order::getPhoneClient()
{
	return phoneClient;
}

string Order::getCar()
{
	string buf = "";
	buf += car.getNum();
	buf += " ";
	buf += car.getColor();
	buf += " ";
	buf += car.getModel();
	buf += " ";
	buf += car.driver.getName();
	buf += " ";
	buf += car.driver.getPhone();
	return buf;
}

void Order::setDriverMark(int mark)
{
	this->DriverMark = mark;
}

void Order::setPassengerMark(int mark)
{
	this->PassengerMark = mark;
}

float Order::calcPrice()
{
	float orderPrice = 0;
	if (car.getType() == "эконом")
	{
		orderPrice += distance * 25;
		if (orderPrice < 65) return 65;
		else return orderPrice;
	}
	else if (car.getType() == "комфорт")
	{
		orderPrice += distance * 40;
		if (orderPrice < 99) return 99;
		else return orderPrice;
	}
	else
	{
		orderPrice += distance * 75;
		if (orderPrice < 275) return 275;
		else return orderPrice;
	}
}
