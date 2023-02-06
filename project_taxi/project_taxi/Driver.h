#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Driver
{
	string name;
	string phone;
	float rating;
	vector<int> marks;
	float profit=0;
	int numTrips = 0;
public:
	Driver(){}
	Driver(string name, string phone);
	float getDriverRating();
	string getName();
	string getPhone();
	void setName(string name);
	void setPhone(string phone);
	void changeProfit(float orderPrice);
//private:
	float calcRating(vector<int> marks);
};

