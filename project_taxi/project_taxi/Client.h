#pragma once
#include <iostream>
#include "windows.h"
//#include "DataBase.h"
#include "User.h"
#include "Order.h"
using namespace std;
class Order;
class Client :public User
{
	string login;
	string password;
	string name;
	string phone;
	float rating;
	vector<int> marks;
	int numOrders;
	float discount;
public:
	Client(){}
	Client(string login, string password);
	Client(string login, string password, string name, string phone);
	string getLogin();
	string getPassword();
	string getData();
	float getPassengerRating();
	float getDiscount();
	string getNameUser();
	string getPhoneUser();
private:
	float calcRating(vector<int> marks);
public:
	void signUp();
	void menu();
	void showInfo();
	Order callATaxi();
	void acceptOrder(DataBase base);
};

