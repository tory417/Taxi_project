#pragma once
//#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include "DataBase.h"
#include "Time.h"
#include "Car.h"
using namespace std;
class Order
{
	int number;
	//string realTime;
	string coordA;
	string coordB;
	float distance;
	string nameClient;
	string phoneClient;
	float price;
	int DriverMark;
	int PassengerMark;
public:
	Car car;
	Order(){}
	Order(int number, string coordA, string coordB, float distance, string name, string phone);
	void setCar(Car car);
	float getOrderPrice();
	int getOrderNumber();
	string getTime();
	//string getRealTime();
	string getA();
	string getB();
	float getDistance();
	string getNameClient();
	string getPhoneClient();
	string getCar();
	void setDriverMark(int mark);
	void setPassengerMark(int mark);
private:
	float calcPrice();
};

