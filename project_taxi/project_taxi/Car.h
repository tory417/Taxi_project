#pragma once
#include <iostream>
#include "Driver.h"
using namespace std;
class Car
{
	string number;
	string color;
	string model;
	string type;
public:
	Driver driver;
	Car(){}
	Car(string number, string color, string model, string type);
	Car(Driver driver);
	string getNum();
	string getColor();
	string getModel();
	string getDriver();
	string getType();
	void setNum(string num);
	void setColor(string color);
	void setModel(string model);
	void setType(string type);
	//void getDriver(stri);
	void setDriver(Driver driver);
};

