#pragma once
#include "Order.h"
class Ordinary_order : public Order
{
protected:
	string description;
	float price;
public:
	Ordinary_order();
	Ordinary_order(Date order_date, Time order_time, string description, float price);
	virtual ~Ordinary_order();

	string get_description()const;
	float get_price()const;

	void set_description(string description);
	void set_price(float price);

	virtual void show()const override;
	virtual string type() const override;

	virtual string toString()const override;
	virtual void save(ofstream& file)override;
	virtual void load(string row)override;
};

