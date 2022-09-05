#include "Insured_order.h"

Insured_order::Insured_order() :Ordinary_order(order_date, order_time, description, price)
{
	name_company = "";
	money_amount = 0;
}

Insured_order::Insured_order(Date order_date, Time order_time, string description, float price, string name_company, float money_amount) :Ordinary_order(order_date, order_time, description, price)
{
	if (name_company != "")
	{
		this->name_company = name_company;
		if (money_amount >= 0)
		{
			this->money_amount = money_amount;
			number = amount;
		}
		else throw new Price_exception;
	}
	else throw new Courier_exception;
}

Insured_order::~Insured_order()
{
}

string Insured_order::get_name_company() const
{
	return name_company;
}

float Insured_order::get_money_amount() const
{
	return money_amount;
}

void Insured_order::set_name_company(string name_company)
{
	if (name_company != "")
	{
		this->name_company = name_company;
	}
	else throw new Courier_exception;
}

void Insured_order::set_money_amount(float money_amount)
{
	if (money_amount >= 0)
	{
		this->money_amount = money_amount;
		number = ++amount;
	}
	else throw new Price_exception;
}

void Insured_order::show() const
{
	cout << type() << " ¹: " << number << " =====" << endl;
	cout << "========================\n";
	cout << " " << order_date << "  " << order_time << endl;
	cout << "========================\n";
	cout << " description:\t" << description << endl;
	cout << " price:\t" << price << endl;
	cout << " name_company:\t" << name_company << endl;
	cout << " money_amount:\t" << money_amount << endl;
	cout << "\n\n";
}

string Insured_order::type() const
{
	return "Insured_order";
}

string Insured_order::toString() const
{
	return to_string(number) + " " + to_string(order_date.getYear()) + "." + to_string(order_date.getMonth()) + "." + to_string(order_date.getDay()) + " " + to_string(order_time.getHour()) + ":" + to_string(order_time.getMinutes()) + ":" + to_string(order_time.getSeconds()) + " " + description + " " + to_string(price) + " " + name_company + " " + to_string(money_amount);
}

void Insured_order::save(ofstream& file)
{
	file << type() << " ";
	file << toString() << endl;
}

string Insured_order::load(ifstream& file)
{
	string tmp;
	tmp += Ordinary_order::load(file);

	while (!file.eof())
	{
		name_company = tmp.substr(0, tmp.find(" "));
		tmp.erase(0, tmp.find(" ") + 1);

		money_amount = atof(tmp.c_str());
		tmp.erase(0, tmp.find(" ") + 1);
		break;
	}
	return tmp;
}
