#include "Operator.h"

Operator::Operator(string login, string password, string name, string num)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->num = num;
}

void Operator::signUp()
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

void Operator::menu()
{
	cout << "1. ������ ����������" << endl;
	cout << "2. ������� �����" << endl;
	cout << "3. �������� ���������" << endl;
	cout << "4. �������� ������" << endl;
	//cout << "5. �������� ���������� � ������� ����������� ��������" << endl;
	cout << "5. �������� ���������� � ������� ����������� ���������" << endl;
	cout << "6. �������� ���������� � ������� �� ���������� ������" << endl;
	cout << "0. �����" << endl;
}

void Operator::showInfo()
{
	cout << "�����" << "\t" << "������" << "\t" << "���" << "\t" << "��������� �����" << endl;
	cout << login << "\t" << password << "\t" << name << "\t" << num << endl;
}

string Operator::getLogin()
{
	return login;
}

string Operator::getPassword()
{
	return password;
}

string Operator::getData()
{
	string buf = "";
	buf += name;
	buf += " ";
	buf += num;
	return buf;
}

string Operator::getNameUser()
{
	return name;
}

string Operator::getPhoneUser()
{
	return num;
}

Order Operator::callATaxi()
{
	return Order();
}

void Operator::acceptOrder(DataBase base)
{
	User* client = base.getPassenger();
	string namePassenger = client->getNameUser();
	string phonePassenger = client->getPhoneUser();
	int num = 100 + rand() % 9901;
	int clas;
	cout << "������� ����� ������:" << endl;
	cout << "1. ������" << endl;
	cout << "2. �������" << endl;
	cout << "3. ������" << endl;
	cin >> clas;
	cout << "������: ";
	string coordA;
	cin >> coordA;
	cout << endl << "����: ";
	string coordB;
	cin >> coordB;
	float distance = (10 + rand() % 200) * 0.1;
	Order newOrder(num, coordA, coordB, distance, namePassenger, phonePassenger);
	if (clas == 1) newOrder.setCar(base.findPos("cars_econom.txt"));
	else if (clas == 2) newOrder.setCar(base.findPos("cars_comfort.txt"));
	else if (clas == 3) newOrder.setCar(base.findPos("cars_business.txt"));
	base.addOrder(newOrder, "orders.txt");
	cout << "��������� �������: " << newOrder.getOrderPrice() << endl;
	/*int mark1 = 1 + rand() % 5;
	cout << "������ ��������: " << mark1 << endl;
	newOrder.setDriverMark(mark1);
	int mark2 = 1 + rand() % 5;
	cout << "������ ���������: " << mark2 << endl;
	newOrder.setPassengerMark(mark2);*/
}
