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
	cout << "��� ����������: ";
	string name;
	cin >> name;
	cout << endl << "��������� �����: ";
	string num;
	cin >> num;
	cout << endl << "����� ��� ����� � �������: ";
	string login;
	cin >> login;
	cout << endl << "������: ";
	string password;
	cin >> password;
	this->name = name;
	this->num = num;
	this->login = login;
	this->password = password;
}

void Admin::menu()
{
	cout << "1. ������ ����������" << endl;
	cout << "2. �������� ������ � ���������" << endl;
	cout << "3. �������� ��������" << endl;
	cout << "4. ��������� �������� �� ������" << endl;
	/*cout << "5. ������ ������ �� ����������" << endl;
	cout << "6. ������ ��������" << endl;*/
	cout << "5. �������� ��� ������" << endl;
	cout << "0. �����" << endl;
}

void Admin::showInfo()
{
	cout << "�����" << "\t" << "������" << "\t" << "���" << "\t" << "��������� �����" << endl;
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
