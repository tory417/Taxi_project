#pragma once
#include <iostream>
#include "User.h"
#include "Order.h"
using namespace std;
class Order;
class Admin :public User
{
	string name;
	string num;
	string login;
	string password;
public:
	Admin(){}
	Admin(string login, string password, string name, string num);
	void signUp();
	void menu();
	void showInfo();
	string getLogin();
	string getPassword();
	string getData();
	string getNameUser();
	string getPhoneUser();
	Order callATaxi();
	void acceptOrder(DataBase base);
};

