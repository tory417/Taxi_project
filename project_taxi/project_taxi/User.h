#pragma once
#include <iostream>
using namespace std;
class DataBase;
class Order;
class User
{
public:
	virtual void signUp() = 0;
	virtual void menu() = 0;
	virtual void showInfo() = 0;
	virtual string getLogin() = 0;
	virtual string getPassword() = 0;
	virtual string getData() = 0;
	virtual string getNameUser() = 0;
	virtual string getPhoneUser() = 0;
	virtual Order callATaxi() = 0;
	virtual void acceptOrder(DataBase base) = 0;
};

