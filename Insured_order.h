#pragma once
#include "Ordinary_order.h"
class Insured_order : public Ordinary_order
{
protected:
	string name_company;
	float money_amount;
public:
	Insured_order();
	Insured_order(Date order_date, Time order_time, string description, float price, string name_company, float money_amount);
	virtual ~Insured_order();

	string get_name_company()const;
	float get_money_amount()const;

	void set_name_company(string name_company);
	void set_money_amount(float money_amount);

	virtual void show()const override;
	virtual string type() const override;

	virtual string toString()const override;
	virtual void save(ofstream& file)override;
	virtual string load(ifstream& file)override;
};

