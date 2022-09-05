#pragma once
#include"Date.h"
#include"Time_.h"
#include<string>
#include<fstream>
#include<iostream>

#include"Order_exceptions.h"
using namespace std;

class Order
{
protected:
	Date order_date;
	Time order_time;
	int number;
	static int amount;
public:
	Order();
	Order(Date order_date,Time order_time);
	virtual ~Order();
	Date get_order_date()const;
	Time get_order_time()const;

	static int getAmount();
	int get_number()const;

	/*void set_order_date(Date order_date);
	void set_order_time(Time order_time);
	void setAmount();*/

	virtual void show()const = 0;
	virtual string type() const = 0;

	virtual string toString()const = 0;
	virtual void save(ofstream& file) = 0;
	virtual string load(ifstream& file) = 0;

	bool operator<(const Order& obj) const&;
};



