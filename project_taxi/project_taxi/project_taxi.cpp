#include <iostream>
#include <random>
#include "DataBase.h"
#include "ClientFactory.h"
#include "OperatorFactory.h"
#include "AdminFactory.h"
using namespace std;

string generationCarNumber()
{
    string result = "";
    string letters = "ABEKMHOPCTYX";
    string digits = "0123456789";
    result += letters.substr(rand() % 12, 1);
    result += digits.substr(rand() % 10, 1);
    result += digits.substr(rand() % 10, 1);
    result += digits.substr(rand() % 10, 1);
    result += letters.substr(rand() % 12, 1);
    result += letters.substr(rand() % 12, 1);
    return result;
}

void menuClient(User* us, DataBase generalBase, string clients, string orders, string carsEconom, string carsComfort, string carsBusiness)
{
    int choise2;
    do
    {
        us->menu();
        cin >> choise2;
        switch (choise2)
        {
        case 1:
        {
            us->showInfo();
            break;
        }
        case 2:
        {
            generalBase.getOrdersClient(us->getPhoneUser());
            break;
        }
        case 3:
        {
            int clas;
            cout << "Введите класс машины:" << endl;
            cout << "1. Эконом" << endl;
            cout << "2. Комфорт" << endl;
            cout << "3. Бизнес" << endl;
            cin >> clas;
            Order newOrder = us->callATaxi();
            if (clas == 1) newOrder.setCar(generalBase.findPos(carsEconom));
            else if (clas == 2) newOrder.setCar(generalBase.findPos(carsComfort));
            else if (clas == 3) newOrder.setCar(generalBase.findPos(carsBusiness));
            generalBase.addOrder(newOrder, orders);
            cout << "Машина найдена. Приблизительное время прибытия: " << 1 + rand() % 15 << "мин." << endl;
            cout << "Стоимость поездки: " << newOrder.getOrderPrice() << endl;
            Sleep(1000);
            cout << "Поездка завершена. " << endl;
            /*cout << "Оцените водителя по 5-балльной шкале: " << endl;
            int mark1;
            cin >> mark1;
            newOrder.setDriverMark(mark1);
            int mark2 = 1 + rand() % 5;
            cout << "Оценка пассажира от водителя: " << mark2 << endl;
            newOrder.setPassengerMark(mark2);*/
            break;

        }
        }
    } while (choise2 != 0);
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    DataBase generalBase;
    ClientFactory clFactory;
    OperatorFactory opFactory;
    AdminFactory adFactory;
    string orders("orders.txt");
    string carsEconom("cars_econom.txt");
    string carsComfort("cars_comfort.txt");
    string carsBusiness("cars_business.txt");
    string drivers("drivers.txt");
    string clients("clients.txt");
    string operators("operators.txt");
    string admins("admins.txt");

    //vector<string> colors;
    string colors[10]{ "белый","серый","черный","коричневый","бежевый","серебристый","синий","красный","зелёный","жёлтый" };
    string economModels[]{ "Kia_Ceed","Skoda_Rapid","Renault_Logan","Kia_Rio","Volkswagen_Polo","Hyundai_Solaris"};
    string comfortModels[]{ "Hyundai_i40","Skoda_Octavia","Volkswagen_Jetta","Toyota_Camry","Kia_Optima","Nissan_Teana" };
    string businessModels[]{ "Mercedes_E","Mercedes_S","Audi_A8","BMW_5","Audi_A6","BMW_7" };
    int user = 10;
    do
    {
        cout << "Выберите тип пользователя:" << endl;
        cout << "1. Клиент" << endl;
        cout << "2. Оператор" << endl;
        cout << "3. Администратор" << endl;
        cout << "0. Выход" << endl;
        cin >> user;
        switch (user)
        {
        case 1:
        {
            User* us = clFactory.create();
            cout << "Выберите нужный пункт:" << endl;
            cout << "1. Регистрация" << endl;
            cout << "2. Вход в личный кабинет" << endl;
            cout << "0. Назад" << endl;
            int choice1;
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                us->signUp();
                generalBase.addPassenger(us, clients);
                menuClient(us, generalBase, clients, orders, carsEconom, carsComfort, carsBusiness);
                break;
            }
            case 2:
            {
                string login;
                cout << "Введите логин: ";
                cin >> login;
                string password;
                cout << "Введите пароль: ";
                cin >> password;
                User* client = generalBase.findClient(login, password, clients);
                if ((client->getLogin() != login)|| (client->getPassword() != password)) cout << "Неверный логин или пароль" << endl;
                else
                {
                    menuClient(client, generalBase, clients, orders, carsEconom, carsComfort, carsBusiness);
                }
                
                break;
            }
            case 0:
            {
                break;
            }
            }
            break;
        }
        case 2:
        {
            User* us = opFactory.create();
            cout << "Выберите нужный пункт:" << endl;
            cout << "1. Регистрация" << endl;
            cout << "2. Вход в личный кабинет" << endl;
            cout << "0. Назад" << endl;
            int choice1;
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                us->signUp();
                generalBase.addOperator(us, operators);
                int choise2;
                do
                {
                    us->menu();
                    cin >> choise2;
                    switch (choise2)
                    {
                    case 1:
                    {
                        us->showInfo();
                        break;
                    }
                    case 2:
                    {
                        us->acceptOrder(generalBase);
                        break;
                    }
                    case 3:
                    {
                        generalBase.getDrivers(drivers);
                        break;
                    }
                    case 4:
                    {
                        generalBase.getOrders();
                        break;
                    }
                    /*case 5:
                    {
                        string phone;
                        cout << "Введите номер телефона водителя:" << endl;
                        cin >> phone;
                        generalBase.getOrdersDriver(phone);
                        break;
                    }*/
                    case 5:
                    {
                        string phone;
                        cout << "Введите номер телефона пассажира:" << endl;
                        cin >> phone;
                        generalBase.getOrdersClient(phone);
                        break;
                    }
                    case 6:
                    {
                        string number;
                        cout << "Введите номер машины:" << endl;
                        cin >> number;
                        generalBase.getOrdersCar(number);
                        break;
                    }
                    case 0:
                    {
                        break;
                    }
                    }
                } while (choise2 != 0);
                break;
            }
            case 2:
            {
                string login;
                cout << "Введите логин: ";
                cin >> login;
                string password;
                cout << "Введите пароль: ";
                cin >> password;
                User* user = generalBase.findOperator(login, password, operators);
                if ((user->getLogin() != login) || (user->getPassword() != password)) cout << "Неверный логин или пароль" << endl;
                else
                {
                    int choise2;
                    do
                    {
                        user->menu();
                        cin >> choise2;
                        switch (choise2)
                        {
                        case 1:
                        {
                            user->showInfo();
                            break;
                        }
                        case 2:
                        {
                            user->acceptOrder(generalBase);
                            break;
                        }
                        case 3:
                        {
                            generalBase.getDrivers(drivers);
                            break;
                        }
                        case 4:
                        {
                            generalBase.getOrders();
                            break;
                        }
                        /*case 5:
                        {
                            string phone;
                            cout << "Введите номер телефона водителя:" << endl;
                            cin >> phone;
                            generalBase.getOrdersDriver(phone);
                            break;
                        }*/
                        case 5:
                        {
                            string phone;
                            cout << "Введите номер телефона пассажира:" << endl;
                            cin >> phone;
                            generalBase.getOrdersClient(phone);
                            break;
                        }
                        case 6:
                        {
                            string number;
                            cout << "Введите номер машины:" << endl;
                            cin >> number;
                            generalBase.getOrdersCar(number);
                            break;
                        }
                        case 0:
                        {
                            break;
                        }
                        }
                    } while (choise2 != 0);
                }
                
            }
            }
            break;
        }
        case 3:
        {
            User* us = adFactory.create();
            cout << "Выберите нужный пункт:" << endl;
            cout << "1. Регистрация" << endl;
            cout << "2. Вход в личный кабинет" << endl;
            cout << "0. Назад" << endl;
            int choice1;
            cin >> choice1;
            switch (choice1)
            {
            case 1:
            {
                us->signUp();
                generalBase.addAdmin(us, admins);
                int choise2;
                do
                {
                    us->menu();
                    cin >> choise2;
                    switch (choise2)
                    {
                    case 1:
                    {
                        us->showInfo();
                        break;
                    }
                    case 2:
                    {
                        int clas;
                        cout << "Введите класс машины:" << endl;
                        cout << "1. Эконом" << endl;
                        cout << "2. Комфорт" << endl;
                        cout << "3. Бизнес" << endl;
                        cin >> clas;
                        string number = generationCarNumber();
                        int key = rand() % 10;
                        string color = colors[key];
                        //cout << "Введите цвет машины: " << endl;
                        //cin >> color;
                        int key2 = rand() % 6;
                        string model;
                        string type;
                        if (clas == 1)
                        {
                            model = economModels[key2];
                            type = "эконом";
                        }
                        else if (clas == 2)
                        {
                            model = comfortModels[key2];
                            type = "комфорт";
                        }
                        else
                        {
                            model = businessModels[key2];
                            type = "бизнес";
                        }
                        //cout << "Введите модель машины: " << endl;
                        //cin >> model;
                        Car newCar(number, color, model, type);
                        if (clas==1) generalBase.addCar(newCar, carsEconom);
                        else if (clas == 2) generalBase.addCar(newCar, carsComfort);
                        else if (clas == 3) generalBase.addCar(newCar, carsBusiness);
                        cout << "Добавлена новая машина: " << type << " " << number << " " << color << " " << model << endl;
                        break;
                    }
                    case 3:
                    {
                        string name;
                        cout << "Введите имя водителя: " << endl;
                        cin >> name;
                        string phone;
                        cout << "Введите телефон водителя: " << endl;
                        cin >> phone;
                        Driver newDriver(name, phone);
                        generalBase.addDriver(newDriver, drivers);
                        break;

                    }
                    case 4:
                    {
                        int clas;
                        cout << "Введите класс машины:" << endl;
                        cout << "1. Эконом" << endl;
                        cout << "2. Комфорт" << endl;
                        cout << "3. Бизнес" << endl;
                        cin >> clas;
                        string numCar;
                        cout << "Введите номер машины: " << endl;
                        cin >> numCar;
                        string phoneDriver;
                        cout << "Введите номер телефона водителя: " << endl;
                        cin >> phoneDriver;
                        Driver driver1 = generalBase.getDriver(drivers, phoneDriver);
                        if(clas==1) generalBase.setDriver(carsEconom, numCar, driver1);
                        else if (clas == 2) generalBase.setDriver(carsComfort, numCar, driver1);
                        else if (clas == 3) generalBase.setDriver(carsBusiness, numCar, driver1);
                        break;
                    }
                    case 5:
                    {
                        generalBase.getOrders();
                        break;
                    }
                    }
                } while (choise2 != 0);
                break;
            }
            case 2:
            {
                string login;
                cout << "Введите логин: ";
                cin >> login;
                string password;
                cout << "Введите пароль: ";
                cin >> password;
                User* client = generalBase.findAdmin(login, password, admins);
                if ((client->getLogin() != login) || (client->getPassword() != password)) cout << "Неверный логин или пароль" << endl;
                else
                {
                    int choise2;
                    do
                    {
                        client->menu();
                        cin >> choise2;
                        switch (choise2)
                        {
                        case 1:
                        {
                            client->showInfo();
                            break;
                        }
                        case 2:
                        {
                            int clas;
                            cout << "Введите класс машины:" << endl;
                            cout << "1. Эконом" << endl;
                            cout << "2. Комфорт" << endl;
                            cout << "3. Бизнес" << endl;
                            cin >> clas;
                            string number = generationCarNumber();
                            int key = rand() % 10;
                            string color = colors[key];
                            //cout << "Введите цвет машины: " << endl;
                            //cin >> color;
                            int key2 = rand() % 6;
                            string model;
                            string type;
                            if (clas == 1)
                            {
                                model = economModels[key2];
                                type = "эконом";
                            }
                            else if (clas == 2)
                            {
                                model = comfortModels[key2];
                                type = "комфорт";
                            }
                            else
                            {
                                model = businessModels[key2];
                                type = "бизнес";
                            }
                            //cout << "Введите модель машины: " << endl;
                            //cin >> model;
                            Car newCar(number, color, model, type);
                            if (clas == 1) generalBase.addCar(newCar, carsEconom);
                            else if (clas == 2) generalBase.addCar(newCar, carsComfort);
                            else if (clas == 3) generalBase.addCar(newCar, carsBusiness);
                            cout << "Добавлена новая машина: " << type << " " << number << " " << color << " " << model << endl;
                            break;
                        }
                        case 3:
                        {
                            string name;
                            cout << "Введите имя водителя: " << endl;
                            cin >> name;
                            string phone;
                            cout << "Введите телефон водителя: " << endl;
                            cin >> phone;
                            Driver newDriver(name, phone);
                            generalBase.addDriver(newDriver, drivers);
                            break;

                        }
                        case 4:
                        {
                            int clas;
                            cout << "Введите класс машины:" << endl;
                            cout << "1. Эконом" << endl;
                            cout << "2. Комфорт" << endl;
                            cout << "3. Бизнес" << endl;
                            cin >> clas;
                            string numCar;
                            cout << "Введите номер машины: " << endl;
                            cin >> numCar;
                            string phoneDriver;
                            cout << "Введите номер телефона водителя: " << endl;
                            cin >> phoneDriver;
                            Driver driver1 = generalBase.getDriver(drivers, phoneDriver);
                            if (clas == 1) generalBase.setDriver(carsEconom, numCar, driver1);
                            else if (clas == 2) generalBase.setDriver(carsComfort, numCar, driver1);
                            else if (clas == 3) generalBase.setDriver(carsBusiness, numCar, driver1);
                            break;
                        }
                        case 5:
                        {
                            generalBase.getOrders();
                            break;
                        }
                        }
                    } while (choise2 != 0);
                }
                
                break;
            }
            }
        }
        } 
    } while (user != 0);
}

