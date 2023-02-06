#pragma once
#include <iostream>
#include "User.h"
#include "Order.h"
using namespace std;
class Order;
class Operator :public User
{
	string login;
	string password;
	string name;
	string num;
public:
	Operator(){}
	Operator(string login, string password, string name, string num);
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

