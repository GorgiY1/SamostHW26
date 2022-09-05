#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<vector>
#include<algorithm>

#include"Date.h"
#include"Time_.h"

#include"Order.h"
#include"Ordinary_order.h"
#include"Express_Order.h"
#include"Insured_order.h"

#include"Order_exceptions.h"
using namespace std;




class All_orders
{
	vector<Order*>syst;
	vector<Order*>::iterator i = syst.begin();
public:
	All_orders();
	~All_orders();

	void add_order(Order* obj);
	void show_syst();

	void search_by_type(string type);
	void search_by_date(Date critery);
	void search_by_time(Time critery);
	void search_by_description(string description);
	void search_by_price(float price);
	void search_by_courier(string courier);
	void search_by_days_to_deliver(int days_to_deliver);
	void search_by_name_company(string name_company);
	void search_by_days_money_amountr(float money_amount);
	
	void sort_by_number();
	void sort_by_date();
	void sort_by_time();
	void sort_by_description();
	void sort_by_price();
	void sort_by_priority();
	
	void del_by_number(int number);
	void del_by_date(Date critery);
	void del_by_time(Time critery);
	void del_by_description(string description);
	void del_by_price(float price);
	void del_by_type(string type);

	void save(string name_file);
	void load(string name_file);
};

class Compire_by_num : public binary_function<Order*, Order*, bool>
{
public:
	bool operator()(const Order* obj1, const Order* obj2)const
	{
		return ((Ordinary_order*)obj1)->get_number() < ((Ordinary_order*)obj2)->get_number();
	}
};

class Compire_by_date : public binary_function<Order*, Order*, bool>
{
public:
	bool operator()(const Order* obj1, const Order* obj2)const
	{
		return obj1->get_order_date() < obj2->get_order_date();
	}
};

class Compire_by_time : public binary_function<Order*, Order*, bool>
{
public:
	bool operator()(const Order* obj1, const Order* obj2)const
	{
		return obj1->get_order_time() < obj2->get_order_time();
	}
};

class Compire_by_description : public binary_function<Order*, Order*, bool>
{
public:
	bool operator()(const Order* obj1, const Order* obj2)const
	{
		return ((Ordinary_order*)obj1)->get_description() < ((Ordinary_order*)obj2)->get_description();
	}
};

class Compire_by_price : public binary_function<Order*, Order*, bool>
{
public:
	bool operator()(const Order* obj1, const Order* obj2)const
	{
		return ((Ordinary_order*)obj1)->get_price() < ((Ordinary_order*)obj2)->get_price();
	}
};

class Compire_by_type : public binary_function<Order*, Order*, bool>
{
public:
	bool operator()(const Order* obj1, const Order* obj2)const
	{
		return obj1->type() < obj2->type();
	}
};