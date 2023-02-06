#include "DataBase.h"

void DataBase::addCar(Car car, string path)
{
	cars.push_back(car);
	ofstream out(path, ios::app);
	out << cars[cars.size()-1].getNum() << " " << cars[cars.size()-1].getColor() << " " << cars[cars.size()-1].getModel() << " " << cars[cars.size()-1].getType() << endl;
	out.close();
}

void DataBase::addDriver(Driver driver, string path)
{
	drivers.push_back(driver);
	ofstream out(path, ios::app);
	out << drivers[drivers.size()-1].getPhone() << " " << drivers[drivers.size() - 1].getName() << endl;
	out.close();
}

void DataBase::addOrder(Order order, string path)
{
	orders.push_back(order);
	ofstream out(path, ios::app);
	out << order.getOrderNumber() << "\t" << order.getTime() << "\t" << order.getA() << "\t" << order.getB() << "\t" << order.getDistance() << "\t" << order.getNameClient() << " " << order.getPhoneClient() << "\t=" << order.getCar() << "\t" << order.getOrderPrice() << endl;
	out.close();
}

void DataBase::addPassenger(User* passenger, string path)
{
	passengers.push_back(passenger);
	ofstream out(path, ios::app);
	out << passengers[passengers.size()-1]->getLogin() <<" "<< passengers[passengers.size() - 1]->getPassword()<<" "<< passengers[passengers.size() - 1]->getNameUser()<<" "<<passengers[passengers.size() - 1]->getPhoneUser() << endl;
	out.close();
}

void DataBase::addOperator(User* oper, string path)
{
	users.push_back(oper);
	ofstream out(path, ios::app);
	out << users[users.size() - 1]->getLogin() << " " << users[users.size() - 1]->getPassword() << " " << users[users.size() - 1]->getNameUser() << " " << users[users.size() - 1]->getPhoneUser() << endl;
	out.close();
}

void DataBase::addAdmin(User* admin, string path)
{
	users.push_back(admin);
	ofstream out(path, ios::app);
	out << users[users.size() - 1]->getLogin() << " " << users[users.size() - 1]->getPassword() << " " << users[users.size() - 1]->getNameUser() << " " << users[users.size() - 1]->getPhoneUser() << endl;
	out.close();
}

User* DataBase::findClient(string login, string password, string path)
{
	string buf = "";
	string str;
	string log;
	string pass;
	string name;
	string phone;
	ifstream in(path);
	if (in.is_open())
	{
		
		while (!in.eof())
		{
			getline(in, str);

			int k = 0;
			for (int i = 0; str.length(); i++, k++)
			{
				if (str[i] == ' ')
				{
					k++;
					break;
				}
				else buf += str[i];

			}
			if (buf == login)
			{
				log = buf;
				buf = "";
				for (; str[k] != ' ';)
				{
					buf += str[k++];
				}
				k++;
				pass = buf;
				buf = "";
				for (; str[k] != ' ';)
				{
					buf += str[k++];
				}
				k++;
				name = buf;
				buf = "";
				for (; str[k]!='\0';)
				{
					buf += str[k++];
				}
				phone = buf;
				User* client = new Client(log, pass, name, phone);
				return client;
			}
			else buf = "";
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

User* DataBase::findOperator(string login, string password, string path)
{
	string buf = "";
	string log;
	string pass;
	string name;
	string num;
	ifstream in(path);
	if (in.is_open())
	{
		string str;
		while (!in.eof())
		{
			getline(in, str);

			int k = 0;
			for (int i = 0; str.length(); i++, k++)
			{
				if (str[i] == ' ')
				{
					k++;
					break;
				}
				else buf += str[i];

			}
			if (buf == login)
			{
				log = buf;
				buf = "";
				for (; str.length();)
				{
					if (str[k] == ' ') break;
					buf += str[k++];
				}
				k++;
				pass = buf;
				buf = "";
				for (; str.length();)
				{
					if (str[k] == ' ') break;
					buf += str[k++];
				}
				k++;
				name = buf;
				buf = "";
				for (; str[k] != '\0';)
				{
					buf += str[k++];
				}
				num = buf;
				User* oper = new Operator(log, pass, name, num);
				return oper;
			}
			else buf = "";
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

User* DataBase::findAdmin(string login, string password, string path)
{
	string buf = "";
	string log;
	string pass;
	string name;
	string num;
	ifstream in(path);
	if (in.is_open())
	{
		string str;
		while (!in.eof())
		{
			getline(in, str);

			int k = 0;
			for (int i = 0; str.length(); i++, k++)
			{
				if (str[i] == ' ')
				{
					k++;
					break;
				}
				else buf += str[i];

			}
			if (buf == login)
			{
				log = buf;
				buf = "";
				for (; str.length();)
				{
					if (str[k] == ' ') break;
					buf += str[k++];
				}
				pass = buf;
				buf = "";
				for (; str.length();)
				{
					if (str[k] == ' ') break;
					buf += str[k++];
				}
				name = buf;
				buf = "";
				for (; str[k] != '\0';)
				{
					buf += str[k++];
				}
				num = buf;
				User* oper = new Admin(log, pass, name, num);
				return oper;
			}
			else buf = "";
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

Car DataBase::findPos(string path)
{
	//cout << "begin find car" << endl;
	ifstream in(path);
	string num;
	string color;
	string model;
	string type;
	string str;
	int iter=0;
	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str);
			iter++;
		}
		if (iter == 0)
		{
			cout << "Машин такого класса нет. Попробуйте позже" << endl;
			return Car();
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
	ifstream fin(path);
	if (fin.is_open())
	{
		int key = 1+rand() % (iter-1);
		int result = 0;
		do
		{
			getline(fin, str);
			result++;
		} while (result != key);
	}
	else cout << "Файл не найден" << endl;
	fin.close();
	int x = 0;
	for (int i = 0; str.length(); i++, x++)
	{
		if (str[i] == ' ')
		{
			x++;
			break;
		}
		num += str[i];
	}
	for (; str[x] != ' ';)
	{
		color += str[x++];
	}
	x++;
	for (; str[x] != ' ';)
	{
		model += str[x++];
	}
	x++;
	for (; str[x] != '\0';)
	{
		type += str[x++];
	}
	Car car(num, color, model, type);
	//cout << car.getNum() << car.getColor() << car.getModel() << car.getType() << endl;
	return car;
	
	
	
}

void DataBase::setDriver(string path, string numCar, Driver driver)
{
	fstream fs(path);
	string str;
	string buf;
	string str2 = driver.getName();
	str2 += " ";
	str2 += driver.getPhone();
	if (fs.is_open())
	{
		while (!fs.eof())
		{
			buf = "";
			getline(fs, str);
			for (int i = 0; str[i] != ' '; i++)
			{
				buf += str[i];
			}
			//cout << "buf_set=" << buf << endl;
			//cout << "str2=" << str2 << endl;
			if (buf == numCar)
			{
				fs << (str2) << endl;
				/*str += " ";
				str += str2;
				cout << "str=" << str << endl;
				fs << (str) << endl;*/
				break;
			}
		}
	}
	else cout << "Файл не найден" << endl;
	fs.close();
}

Driver DataBase::getDriver(string path, string phoneDriver)
{
	ifstream in(path);
	string str;
	string buf;
	string name;
	if (in.is_open())
	{
		while (!in.eof())
		{
			str = "";
			buf = "";
			int iter = 0;
			getline(in, str);
			for (int i = 0; str[i] != ' '; i++, iter++)
			{
				buf += str[i];
			}
			cout << "buf=" << buf << endl;
			iter++;
			cout << "iter=" << iter << endl;
			if (buf == phoneDriver)
			{
				for (; str[iter]!='\0';)
				{
					name += str[iter++];
					cout << "name=" << name;
				}
				cout << "buf=" << buf;
				cout << "name=" << name << endl;
				Driver driver(name, buf);
				return driver;
				break;
			}
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
	
}

void DataBase::getOrdersClient(string phone)
{
	cout << "№ заказа" << "\t" << "Время заказа" << "\t" << "Откуда" << "\t" << "Куда" << "\t" << "Расстояние(км)" << "\t" << "Данные водителя" << "\t\t\t" << "Стоимость поездки" << endl;
	ifstream in("orders.txt");
	
	if (in.is_open())
	{
		while (!in.eof())
		{
			string str = "";
			string buf = "";
			int key = 0;
			getline(in, str);
			key = str.find('+');
			if (key < 0) break;
			for (; str[key] != '\t';)
			{
				buf += str[key++];
			}
			if (buf == phone)
			{
				cout << str;
			}
			cout << endl;
			
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

void DataBase::getOrdersDriver(string phone)
{
	cout << "Номер заказа" << "\t" << "Время заказа" << "\t" << "Откуда" << "\t" << "Куда" << "\t" << "Расстояние(км)" << "\t" << "Данные клиента" << "\t\t\t" << "Стоимость поездки" << endl;
	ifstream in("orders.txt");
	if (in.is_open())
	{
		for (int i = 0; i < orders.size(); i++)
		{
			//if (orders[i].car.driver.getPhone()==phone) cout << orders[i].getOrderNumber() << "\t" << orders[i].getRealTime() << "\t" << orders[i].getA() << "\t" << orders[i].getB() << "\t" << orders[i].getDistance() << "\t" << orders[i].getNameClient() <<" "<<orders[i].getPhoneClient() << "\t" << orders[i].getOrderPrice() << endl;
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

void DataBase::getOrdersCar(string number)
{
	cout << "Номер заказа" << "\t" << "Время заказа" << "\t" << "Откуда" << "\t" << "Куда" << "\t" << "Расстояние(км)" << "\t" << "Данные клиента" << "\t\t" << "Данные водителя" << "\t\t\t" << "Стоимость поездки" << endl;
	ifstream in("orders.txt");
	if (in.is_open())
	{
		while (!in.eof())
		{
			string str = "";
			string buf = "";
			int key = 0;
			getline(in, str);
			key = str.find('=');
			if (key < 0) break;
			key++;
			for (; str[key] != ' ';)
			{
				buf += str[key++];
			}
			if (buf == number)
			{
				cout << str;
			}
			cout << endl;

		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

void DataBase::getOrders()
{
	cout << "№ заказа" << "\t" << "Время" << "\t\t" << "Откуда" << "\t" << "Куда" << "\t" << "Расстояние(км)" << "\t" << "Данные клиента" << "\t\t" << "Данные водителя" << "\t\t" << "Стоимость поездки" << endl;
	ifstream in("orders.txt");
	if (in.is_open())
	{
		string str;
		while (!in.eof())
		{
			getline(in, str);
			cout << str << endl;
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

void DataBase::getCars()
{
	
}

void DataBase::getDrivers(string path)
{
	ifstream in(path);
	
	if (in.is_open())
	{
		cout << "Имя водителя" << "\t" << "Номер телефона" << endl;
		string str;
		while (!in.eof())
		{
			getline(in, str);
			cout << str << endl;
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();
}

User* DataBase::getPassenger()
{
	ifstream in("clients.txt");
	string str0;
	string str="";
	int iter = 0;
	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str0);
			iter++;
		}
	}
	in.close();
	in.open("clients.txt");
	if (in.is_open())
	{
		int key = 1+rand() % (iter-1);
		int result = 1;
		while (result<=key)
		{
			getline(in, str);
			result++;
		}
	}
	else cout << "Файл не найден" << endl;
	in.close();

	string name = "";
	string phone = "";
	string login = "";
	string pass = "";
	int x = 0;
	for (int i = 0; str[i] != ' '; i++, x++)
	{
		login += str[i];
	}
	x++;
	for (; str[x] != ' ';)
	{
		pass += str[x++];
	}
	x++;
	for (; str[x] != ' ';)
	{
		name += str[x++];
	}
	x++;
	for (; str[x] != '\0';)
	{
		phone += str[x++];
	}
	User* client = new Client(login, pass, name, phone);
	return client;
}

void DataBase::getUsers()
{
	for (int i = 0; i < users.size(); i++)
	{
		users[i]->showInfo();
	}
}
