#pragma once
#include"Ordinary_order.h"
class Express_Order : public Ordinary_order
{
protected:
	string courier;
	int days_to_deliver;
public:
	Express_Order();
	Express_Order(Date order_date, Time order_time, string description, float price, string courier, int days_to_deliver);
	virtual ~Express_Order();
	string get_courier()const;
	int get_days_to_deliver()const;

	void set_courier(string courier);
	void set_days_to_deliver(int days_to_deliver);

	static int getAmount();

	virtual void show()const override;
	virtual string type() const override;

	virtual string toString()const override;
	virtual void save(ofstream& file) override;
	virtual void load(string row) override;
};

