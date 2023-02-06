#include "Admin.h"

Admin::Admin(string login, string password, string name, string num)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->num = num;
}

void Admin::signUp()
{
	cout << "ФИО сотрудника: ";
	string name;
	cin >> name;
	cout << endl << "Табельный номер: ";
	string num;
	cin >> num;
	cout << endl << "Логин для входа в систему: ";
	string login;
	cin >> login;
	cout << endl << "Пароль: ";
	string password;
	cin >> password;
	this->name = name;
	this->num = num;
	this->login = login;
	this->password = password;
}

void Admin::menu()
{
	cout << "1. Данные сотрудника" << endl;
	cout << "2. Добавить машину в таксопарк" << endl;
	cout << "3. Добавить водителя" << endl;
	cout << "4. Назначить водителя на машину" << endl;
	/*cout << "5. Убрать машину из таксопарка" << endl;
	cout << "6. Убрать водителя" << endl;*/
	cout << "5. Показать все заказы" << endl;
	cout << "0. Выход" << endl;
}

void Admin::showInfo()
{
	cout << "Логин" << "\t" << "Пароль" << "\t" << "ФИО" << "\t" << "Табельный номер" << endl;
	cout << login << "\t" << password << "\t" << name << "\t" << num << endl;
}

string Admin::getLogin()
{
	return login;
}

string Admin::getPassword()
{
	return password;
}

string Admin::getData()
{
	string buf = "";
	buf += name;
	buf += " ";
	buf += num;
	return buf;
}

string Admin::getNameUser()
{
	return name;
}

string Admin::getPhoneUser()
{
	return num;
}

Order Admin::callATaxi()
{
	return Order();
}

void Admin::acceptOrder(DataBase base)
{
}
