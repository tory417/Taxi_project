#include "Client.h"


Client::Client(string login, string password)
{
	this->login = login;
	this->password = password;
}

Client::Client(string login, string password, string name, string phone)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->phone = phone;
}

string Client::getLogin()
{
	return login;
}

string Client::getPassword()
{
	return password;
}

string Client::getData()
{
	string buf = "";
	buf += name;
	buf += " ";
	buf += phone;
	buf += " ";
	buf += rating;
	buf += " ";
	buf += discount;
	return buf;
}

float Client::getPassengerRating()
{
	return 0.0f;
}

float Client::getDiscount()
{
	return 0.0f;
}

string Client::getNameUser()
{
	return name;
}

string Client::getPhoneUser()
{
	return phone;
}

float Client::calcRating(vector<int> marks)
{
	int sum = 0;
	for (int i = 0; i < marks.size(); i++)
	{
		sum += marks[i];
	}
	return sum / numOrders;
}

void Client::signUp()
{
	string login;
	string password;
	string name;
	string phone;
	cout << "Введите логин:";
	cin >> login;
	cout << "Введите пароль:";
	cin >> password;
	cout << "Введите Ваше имя:";
	cin >> name;
	cout << "Введите номер телефона:";
	cin >> phone;
	this->login = login;
	this->password = password;
	this->name = name;
	this->phone = phone;
}

void Client::menu()
{
	
	cout << "1. Профиль" << endl;
	cout << "2. История заказов" << endl;
	cout << "3. Вызвать такси" << endl;
	cout << "0. Выход" << endl;
	
}

void Client::showInfo()
{
	cout << "Логин" << "\t" << "Пароль" << "\t" << "Имя" << "\t" << "Телефон" << "\t\t" << "Рейтинг" << "\t" << "Размер скидки" << endl;
	cout << login << "\t" << password << "\t" << name << "\t" << phone << "\t" << rating << "\t" << discount << endl;
}

Order Client::callATaxi()
{
	int num = 100 + rand() % 9901;
	cout << "Откуда: ";
	string coordA;
	cin >> coordA;
	cout << endl << "Куда: ";
	string coordB;
	cin >> coordB;
	float distance = (10 + rand() % 200) * 0.1;
	Order order(num, coordA, coordB, distance, this->name, this->phone);
	cout << "Идёт поиск машины...";
	Sleep(2000);
	return order;
}

void Client::acceptOrder(DataBase base)
{
}
