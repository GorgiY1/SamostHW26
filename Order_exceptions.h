#pragma once
#include<iostream>
#include"Order.h"
using namespace std;

class Order_exceptions
{
protected:
	/*Order*obj;*/
public:
	/*Order_exceptions()
	{
		this->obj = nullptr;
	}
	Order_exceptions(Order*tmp)
	{
		this->obj = tmp;
	}*/
	virtual void show_message() = 0;
};

class Date_exception : public Order_exceptions
{
public:
	/*Date_exception(Order* tmp)
	{
		this->obj = tmp;
	}*/
	virtual void show_message()override
	{
		cout << "\nWarning!\n";
		
		cout << "Don't create a date less than today's day\n\n";
	}
};

class Time_exception : public Order_exceptions
{
public:
	virtual void show_message()override
	{
		cout << "\nWarning! Don't make a time less than present time\n\n";
	}
};

class Price_exception : public Order_exceptions
{
public:
	virtual void show_message()override
	{
		cout << "\nWarning! The Order price need be bigger less zero or equal zero\n\n";
	}
};

class Courier_exception : public Order_exceptions
{
public:
	virtual void show_message()override
	{
		cout << "\nWarning! Name wasn't set!\n\n";
	}
};

class Days_to_deliver_exception : public Order_exceptions
{
public:
	virtual void show_message()override
	{
		cout << "\nWarning! Days to deliver will be bigger than zero or equal to zero!\n\n";
	}
};