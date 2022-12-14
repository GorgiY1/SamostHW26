#include "Express_Order.h"

Express_Order::Express_Order()//:Ordinary_order(order_date, order_time, description, price)
{
	 order_date = Date(0, 0, 0);
    order_time = Time(0, 0, 0);
    description = "";
    price = 0;
	courier = "";
	days_to_deliver = 0;
}

Express_Order::Express_Order(Date order_date, Time order_time, string description, float price,string courier, int days_to_deliver):Ordinary_order(order_date, order_time,description, price)
{
	if (days_to_deliver >= 0)
	{
		this->days_to_deliver = days_to_deliver;
		if (courier != "")
		{
			this->courier = courier;
			number = amount;
		}
		else throw new Courier_exception;
	}
	else throw new Days_to_deliver_exception;
	
}

Express_Order::~Express_Order()
{
}

string Express_Order::get_courier() const
{
	return courier;
}

int Express_Order::get_days_to_deliver() const
{
	return days_to_deliver;
}

void Express_Order::set_courier(string courier)
{
	// the courier must not have a name
	if (courier != "")
	{
		this->courier = courier;
		number = ++amount;
	}
	else throw new Price_exception;
}

void Express_Order::set_days_to_deliver(int days_to_deliver)
{
	// days_to_deliver cannot be less than zero
	if (days_to_deliver >= 0)
	{
		this->days_to_deliver = days_to_deliver;
	}
	else throw new Days_to_deliver_exception;
}

int Express_Order::getAmount()
{
	return amount;
}

void Express_Order::show() const
{
	cout << type() << " ?: " << number << " =====" << endl;
	cout << "========================\n";
	cout << " " << order_date << " " << order_time << endl;
	cout << "========================\n";
	cout << " description:\t" << description << endl;
	cout << " price:\t" << price << endl;
	cout << " name of courier:\t" << courier << endl;
	cout << " days_to_deliver:\t" << days_to_deliver << endl;
	cout << "\n\n";
}

string Express_Order::type() const
{
	return "Express_Order";
}

string Express_Order::toString() const
{
	return to_string(number) + " " + to_string(order_date.getYear()) + "." + to_string(order_date.getMonth()) + "." + to_string(order_date.getDay()) + " " + to_string(order_time.getHour()) + ":" + to_string(order_time.getMinutes()) + ":" + to_string(order_time.getSeconds()) + " " + description + " " + to_string(price) + " " + courier + " " + to_string(days_to_deliver) + " ";

}

void Express_Order::save(ofstream& file)
{
	file << type() << " ";
	file << toString() << endl;
}

void Express_Order::load(string row)
{
	row.erase(0, row.find(" ") + 1);

	number = atoi(row.c_str());
	row.erase(0, row.find(" ") + 1);

	order_date.setYear(atoi(row.c_str()));
	row.erase(0, row.find(".") + 1);

	order_date.setMonth(atoi(row.c_str()));
	row.erase(0, row.find(".") + 1);

	order_date.setDay(atoi(row.c_str()));
	row.erase(0, row.find(" ") + 1);

	order_time.setHour(atoi(row.c_str()));
	row.erase(0, row.find(":") + 1);

	order_time.setMinutes(atoi(row.c_str()));
	row.erase(0, row.find(":") + 1);

	order_time.setSeconds(atoi(row.c_str()));
	row.erase(0, row.find(" ") + 1);

	description = row.substr(0, row.find(" "));
	row.erase(0, row.find(" ") + 1);

	price = atof(row.c_str());
	row.erase(0, row.find(" ") + 1);

	courier = row.substr(0, row.find(" "));
	row.erase(0, row.find(" ") + 1);

	days_to_deliver = atoi(row.c_str());
	row.erase(0, row.find(" ") + 1);
}
