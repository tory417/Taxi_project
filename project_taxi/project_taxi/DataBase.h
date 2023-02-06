#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Car.h"
#include "Driver.h"
#include "Client.h"
#include "Operator.h"
#include "Admin.h"

using namespace std;
class User;
class Order;
class DataBase
{
	vector<Car> cars;
	vector<Driver> drivers;
	vector<User*> passengers;
	vector<Order> orders;
	vector<User*> users;
public:
	void addCar(Car car, string path);
	void addDriver(Driver driver, string path);
	void addOrder(Order order, string path);
	void addPassenger(User* passenger, string path);
	void addOperator(User* oper, string path);
	void addAdmin(User* admin, string path);
	User* findClient(string login, string password, string path);
	User* findOperator(string login, string password, string path);
	User* findAdmin(string login, string password, string path);
	Car findPos(string path);
	void setDriver(string path, string numCar, Driver driver);
	Driver getDriver(string path, string phoneDriver);
	void getOrdersClient(string phone);
	void getOrdersDriver(string phone);
	void getOrdersCar(string number);
	void getOrders();
	void getCars();
	void getDrivers(string path);
	User* getPassenger();
	void getUsers();
};

