#include "Order.h"

Order::Order()
{
	order_date = Date(0, 0, 0);
	order_time = Time(0,0,0);
	number = 0;
}

Order::Order(Date order_date, Time order_time)
{
	if (order_date >= Date())
	{
		this->order_date = order_date;
		if (order_time >= Time())
		{
			this->order_time = order_time;
		}
		else throw new Time_exception;
	}
	else throw new Date_exception;
	
}

Order::~Order()
{
}

Date Order::get_order_date() const
{
	return order_date;
}

Time Order::get_order_time() const
{
	return order_time;
}

int Order::getAmount() 
{
	return amount;
}

int Order::get_number() const
{
	return number;
}

//void Order::set_order_date(Date order_date)
//{
//	if (order_date >= Date())
//	{
//		this->order_date = order_date;
//	}
//	else throw new Date_exception;
//}
//
//void Order::set_order_time(Time order_time)
//{
//	if (order_time >= Time())
//	{
//		this->order_time = order_time;
//	}
//	else throw new Time_exception;
//	
//}
//
//void Order::setAmount()
//{
//	number = --amount;
//}

void Order::show() const
{
	
}

bool Order::operator<(const Order& obj) const&
{
	return this->type() < obj.type();
}
