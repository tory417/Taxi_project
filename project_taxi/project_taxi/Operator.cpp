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

void Operator::menu()
{
	cout << "1. Данные сотрудника" << endl;
	cout << "2. Принять заказ" << endl;
	cout << "3. Показать водителей" << endl;
	cout << "4. Показать заказы" << endl;
	//cout << "5. Показать информацию о заказах конкретного водителя" << endl;
	cout << "5. Показать информацию о заказах конкретного пассажира" << endl;
	cout << "6. Показать информацию о заказах на конкретной машине" << endl;
	cout << "0. Выход" << endl;
}

void Operator::showInfo()
{
	cout << "Логин" << "\t" << "Пароль" << "\t" << "ФИО" << "\t" << "Табельный номер" << endl;
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
	cout << "Введите класс машины:" << endl;
	cout << "1. Эконом" << endl;
	cout << "2. Комфорт" << endl;
	cout << "3. Бизнес" << endl;
	cin >> clas;
	cout << "Откуда: ";
	string coordA;
	cin >> coordA;
	cout << endl << "Куда: ";
	string coordB;
	cin >> coordB;
	float distance = (10 + rand() % 200) * 0.1;
	Order newOrder(num, coordA, coordB, distance, namePassenger, phonePassenger);
	if (clas == 1) newOrder.setCar(base.findPos("cars_econom.txt"));
	else if (clas == 2) newOrder.setCar(base.findPos("cars_comfort.txt"));
	else if (clas == 3) newOrder.setCar(base.findPos("cars_business.txt"));
	base.addOrder(newOrder, "orders.txt");
	cout << "Стоимость поездки: " << newOrder.getOrderPrice() << endl;
	/*int mark1 = 1 + rand() % 5;
	cout << "Оценка водителя: " << mark1 << endl;
	newOrder.setDriverMark(mark1);
	int mark2 = 1 + rand() % 5;
	cout << "Оценка пассажира: " << mark2 << endl;
	newOrder.setPassengerMark(mark2);*/
}
