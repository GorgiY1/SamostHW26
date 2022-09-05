#include "Ordinary_order.h"
#include<cstring>
Ordinary_order::Ordinary_order()//:Order(order_date, order_time)
{
    order_date = Date(0, 0, 0);
    order_time = Time(0, 0, 0);
    description = "";
    price = 0;
}

Ordinary_order::Ordinary_order(Date order_date, Time order_time, string description, float price):Order(order_date, order_time)
{
    this->description = description;
    if (price >= 0)
    {
        this->price = price;
        number = ++amount;
    }
    else throw new Price_exception;
}

Ordinary_order::~Ordinary_order()
{
}

string Ordinary_order::get_description() const
{
    return description;
}

float Ordinary_order::get_price() const
{
    return price;
}

void Ordinary_order::set_description(string description)
{
    this->description = description;
}

void Ordinary_order::set_price(float price)
{
    if (price >= 0)
    {
        this->price = price;
    }
    else throw new Price_exception;
}

void Ordinary_order::show() const
{
    cout << type() <<" ¹: " << number << " =====" << endl;
    cout << "========================\n";
    cout << " " << order_date << "  " << order_time << endl;
    cout << "========================\n";
    cout << " description:\t" << description << endl;
    cout << " price:\t" << price << endl;
    cout << "\n\n";
}

string Ordinary_order::type() const
{
    return "Ordinary_order";
}

string Ordinary_order::toString() const
{
    return to_string(number) + " " + to_string(order_date.getYear()) + "." + to_string(order_date.getMonth()) + "." + to_string(order_date.getDay()) + " " + to_string(order_time.getHour()) + ":" + to_string(order_time.getMinutes()) + ":" + to_string(order_time.getSeconds()) + " " + description + " " + to_string(price);
}

void Ordinary_order::save(ofstream& file)
{
    file << type() << " ";
    file << toString() << endl;
}

string Ordinary_order::load(ifstream& file)
{
    string tmp = "";
    
    while (!file.eof())
    {
        getline(file, tmp);
        tmp.erase(tmp.find(type()), tmp.find(" ") + 1);

        number = atoi(tmp.c_str());
        tmp.erase(0, tmp.find(" ") + 1);
        
        order_date.setYear(atoi(tmp.c_str()));
        tmp.erase(0, tmp.find(".") + 1);
      
        order_date.setMonth(atoi(tmp.c_str()));
        tmp.erase(0, tmp.find(".") + 1);

        order_date.setDay(atoi(tmp.c_str()));
        tmp.erase(0, tmp.find(" ") + 1);

        order_time.setHour(atoi(tmp.c_str()));
        tmp.erase(0, tmp.find(":") + 1);

        order_time.setMinutes(atoi(tmp.c_str()));
        tmp.erase(0, tmp.find(":") + 1);

        order_time.setSeconds(atoi(tmp.c_str()));
        tmp.erase(0, tmp.find(" ") + 1);
       
        description = tmp.substr(0,tmp.find(" "));
        tmp.erase(0, tmp.find(" ") + 1);

        price = atof(tmp.c_str());
        tmp.erase(0, tmp.find(" ") + 1);
        break;
    }
    return tmp;
}
