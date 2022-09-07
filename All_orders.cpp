#include "All_orders.h"

All_orders::All_orders()
{
}

All_orders::~All_orders()
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		(*(i))->~Order();
	}
}

void All_orders::add_order(Order* obj)
{
	//syst.push_back(obj);
	if (obj->type() == "Ordinary_order")
	{
		syst.push_back(((Ordinary_order*)(obj)));
	}
	if (obj->type() == "Express_Order")
	{
		syst.push_back(((Express_Order*)(obj)));
	}
	if (obj->type() == "Insured_order")
	{
		syst.push_back(((Insured_order*)(obj)));
	}
}

void All_orders::show_syst()
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		(*(i))->show();
	}
}

void All_orders::search_by_type(string type)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->type() == type)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Express_Order*)(*(i)))->type() == type)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Insured_order*)(*(i)))->type() == type)
		{
			(*(i))->show();
			is_found = true;
		} 
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::search_by_date(Date critery)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		//if (((Ordinary_order*)(*(i)))->get_order_date() == Date(atoi(critery.substr(0, critery.find(".")).c_str()), atoi(critery.substr(critery.find(".")+1, critery.find(".")).c_str()), atoi(critery.substr(critery.find(".") + 1, 2).c_str())))
		if (((Ordinary_order*)(*(i)))->get_order_date() == critery)
		{
			(*(i))->show();
			is_found = true;
		}
		else if(((Express_Order*)(*(i)))->get_order_date() == critery)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Insured_order*)(*(i)))->get_order_date() == critery)
		{
			(*(i))->show();
			is_found = true;
		}
		else throw new Search_exception;
	}
	if (is_found == false)
		throw new Search_exception;
}
void All_orders::search_by_time(Time critery)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->get_order_time() == critery)
		{

			(*(i))->show();
			is_found = true;
		}
		else if (((Express_Order*)(*(i)))->get_order_time() == critery)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Insured_order*)(*(i)))->get_order_time() == critery)
		{
			(*(i))->show();
			is_found = true;
		}
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::search_by_description(string description)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->get_description() == description)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Express_Order*)(*(i)))->get_description() == description)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Insured_order*)(*(i)))->get_description() == description)
		{
			(*(i))->show();
			is_found = true;
		}
		
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::search_by_price(float price)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->get_price() == price)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Express_Order*)(*(i)))->get_price() == price)
		{
			(*(i))->show();
			is_found = true;
		}
		else if (((Insured_order*)(*(i)))->get_price() == price)
		{
			(*(i))->show();
			is_found = true;
		}
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::search_by_courier(string courier)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Express_Order*)(*(i)))->get_courier() == courier)
		{
			(*(i))->show();
			is_found = true;
		}
		
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::search_by_days_to_deliver(int days_to_deliver)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Express_Order*)(*(i)))->get_days_to_deliver() == days_to_deliver)
		{
			(*(i))->show();
			is_found = true;
		}
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::search_by_name_company(string name_company)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Insured_order*)(*(i)))->get_name_company() == name_company)
		{
			(*(i))->show();
			is_found = true;
		}
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::search_by_days_money_amountr(float money_amount)
{
	bool is_found = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Insured_order*)(*(i)))->get_money_amount() == money_amount)
		{
			(*(i))->show();
			is_found = true;
		}
	}
	if (is_found == false)
		throw new Search_exception;
}

void All_orders::sort_by_number()
{
	// !!! sorting with a multiset 
	multiset<Order*, Compire_by_num>tmp;
	multiset<Order*, Compire_by_num>::iterator itm = tmp.begin();

	//transformation vector in multiset
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->type() == "Ordinary_order")
		{
			tmp.emplace(((Ordinary_order*)(*(i))));// hand over of object in multiset which got from the vector
		}
		if ((*(i))->type() == "Express_Order")
		{
			tmp.emplace(((Express_Order*)(*(i))));
		}
		if ((*(i))->type() == "Insured_order")
		{ 
			tmp.emplace(((Insured_order*)(*(i))));
		}
	}
	syst.erase(syst.begin(), syst.end());
	
	for (itm = tmp.begin(); itm != tmp.end(); itm++)
	{
		if ((*(itm))->type() == "Ordinary_order")
		{
			syst.push_back(((Ordinary_order*)(*(itm))));
		}
		if ((*(itm))->type() == "Express_Order")
		{
			syst.push_back(((Express_Order*)(*(itm))));
		}
		if ((*(itm))->type() == "Insured_order")
		{
			syst.push_back(((Insured_order*)(*(itm))));
		}
	}
}

void All_orders::sort_by_date()
{
	// !!! sorting with a multiset 
	multiset<Order*, Compire_by_date>tmp;
	multiset<Order*, Compire_by_date>::iterator itm = tmp.begin();
	
	//transformation vector in multiset
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->type() == "Ordinary_order")
		{
			tmp.emplace(((Ordinary_order*)(*(i))));// hand over of object in multiset which got from the vector
		}
		if ((*(i))->type() == "Express_Order")
		{
			tmp.emplace(((Express_Order*)(*(i))));
		}
		if ((*(i))->type() == "Insured_order")
		{
			tmp.emplace(((Insured_order*)(*(i))));
		}
		
	}
	syst.erase(syst.begin(), syst.end());

	for (itm = tmp.begin(); itm != tmp.end(); itm++)
	{
		if ((*(itm))->type() == "Ordinary_order")
		{
			syst.push_back(((Ordinary_order*)(*(itm))));
		}
		if ((*(itm))->type() == "Express_Order")
		{
			syst.push_back(((Express_Order*)(*(itm))));
		}
		if ((*(itm))->type() == "Insured_order")
		{
			syst.push_back(((Insured_order*)(*(itm))));
		}
	}
}
	
void All_orders::sort_by_time()
{
	// !!! sorting with a multiset 
	multiset<Order*, Compire_by_time>tmp;
	multiset<Order*, Compire_by_time>::iterator itm = tmp.begin();

	//transformation vector in multiset
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->type() == "Ordinary_order")
		{
			tmp.emplace(((Ordinary_order*)(*(i)))); // hand over of object in multiset which got from the vector
		}
		if ((*(i))->type() == "Express_Order")
		{
			tmp.emplace(((Express_Order*)(*(i))));
		}
		if ((*(i))->type() == "Insured_order")
		{
			tmp.emplace(((Insured_order*)(*(i))));
		}
	}
	syst.erase(syst.begin(), syst.end());

	for (itm = tmp.begin(); itm != tmp.end(); itm++)
	{
		if ((*(itm))->type() == "Ordinary_order")
		{
			syst.push_back(((Ordinary_order*)(*(itm))));
		}
		if ((*(itm))->type() == "Express_Order")
		{
			syst.push_back(((Express_Order*)(*(itm))));
		}
		if ((*(itm))->type() == "Insured_order")
		{
			syst.push_back(((Insured_order*)(*(itm))));
		}
	}
}

void All_orders::sort_by_description()
{
	multiset<Order*, Compire_by_description>tmp;
	multiset<Order*, Compire_by_description>::iterator itm = tmp.begin();


	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->type() == "Ordinary_order")
		{
			tmp.emplace(((Ordinary_order*)(*(i))));
		}
		if ((*(i))->type() == "Express_Order")
		{
			tmp.emplace(((Express_Order*)(*(i))));
		}
		if ((*(i))->type() == "Insured_order")
		{
			tmp.emplace(((Insured_order*)(*(i))));
		}

	}
	syst.erase(syst.begin(), syst.end());

	for (itm = tmp.begin(); itm != tmp.end(); itm++)
	{
		if ((*(itm))->type() == "Ordinary_order")
		{
			syst.push_back(((Ordinary_order*)(*(itm))));
		}
		if ((*(itm))->type() == "Express_Order")
		{
			syst.push_back(((Express_Order*)(*(itm))));
		}
		if ((*(itm))->type() == "Insured_order")
		{
			syst.push_back(((Insured_order*)(*(itm))));
		}
	}
}

void All_orders::sort_by_price()
{
	multiset<Order*, Compire_by_price>tmp;
	multiset<Order*, Compire_by_price>::iterator itm = tmp.begin();

	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->type() == "Ordinary_order")
		{
			tmp.emplace(((Ordinary_order*)(*(i))));
		}
		if ((*(i))->type() == "Express_Order")
		{
			tmp.emplace(((Express_Order*)(*(i))));
		}
		if ((*(i))->type() == "Insured_order")
		{
			tmp.emplace(((Insured_order*)(*(i))));
		}

	}
	syst.erase(syst.begin(), syst.end());

	for (itm = tmp.begin(); itm != tmp.end(); itm++)
	{
		if ((*(itm))->type() == "Ordinary_order")
		{
			syst.push_back(((Ordinary_order*)(*(itm))));
		}
		if ((*(itm))->type() == "Express_Order")
		{
			syst.push_back(((Express_Order*)(*(itm))));
		}
		if ((*(itm))->type() == "Insured_order")
		{
			syst.push_back(((Insured_order*)(*(itm))));
		}
	}
}

void All_orders::sort_by_priority()
{
	multiset<Order*, Compire_by_type>tmp;
	multiset<Order*, Compire_by_type>::iterator itm = tmp.begin();

	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->type() == "Ordinary_order")
		{
			tmp.emplace(((Ordinary_order*)(*(i))));
		}
		if ((*(i))->type() == "Express_Order")
		{
			tmp.emplace(((Express_Order*)(*(i))));
		}
		if ((*(i))->type() == "Insured_order")
		{
			tmp.emplace(((Insured_order*)(*(i))));
		}

	}
	syst.erase(syst.begin(), syst.end());

	for (itm = tmp.begin(); itm != tmp.end(); itm++)
	{
		if ((*(itm))->type() == "Ordinary_order")
		{
			syst.push_back(((Ordinary_order*)(*(itm))));
		}
		if ((*(itm))->type() == "Express_Order")
		{
			syst.push_back(((Express_Order*)(*(itm))));
		}
		if ((*(itm))->type() == "Insured_order")
		{
			syst.push_back(((Insured_order*)(*(itm))));
		}
	}
}

void All_orders::del_by_number(int number)
{
	bool is_deleted = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->get_number() == number)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			is_deleted = true;
			break;
		}
	}
	if (is_deleted == false)
		throw new Delete_exception;
}

void All_orders::del_by_date(Date critery)
{
	bool is_deleted = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->get_order_date() == critery)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			is_deleted = true;
			break;
		}
	}
	if (is_deleted == false)
		throw new Delete_exception;
}

void All_orders::del_by_time(Time critery)
{
	bool is_deleted = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->get_order_time() == critery)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			is_deleted = true;
			break;
		}
	}
	if (is_deleted == false)
		throw new Delete_exception;
}

void All_orders::del_by_description(string description)
{
	bool is_deleted = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((((Ordinary_order*)(*(i))))->get_description() == description)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			is_deleted = true;
			break;
		}
	}
	if (is_deleted == false)
		throw new Delete_exception;
}

void All_orders::del_by_price(float price)
{
	bool is_deleted = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((((Ordinary_order*)(*(i))))->get_price() == price)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			is_deleted = true;
			break;
		}
	}
	if (is_deleted == false)
		throw new Delete_exception;
}

void All_orders::del_by_type(string type)
{
	bool is_deleted = false;
	for (i = syst.begin(); i != syst.end(); i++)
	{
		vector<Order*>::iterator del = i;
		i++;
		if ((((Ordinary_order*)(*(del))))->type() == type)
		{
			syst.erase(del);
			is_deleted = true;
			break;
		}
	}
	if (is_deleted == false)
		throw new Delete_exception;
}

void All_orders::save(string name_file)
{
	ofstream file(name_file + ".txt");
	if (file.is_open())
	{
		for (int i = 0; i < syst.size(); i++)
		{
			syst.at(i)->save(file);
		}
		file.close();
	}

}

void All_orders::load(string name_file)
{
	ifstream file(name_file + ".txt");

	Order * obj = nullptr;
	if (file.is_open())
	{
		string tmp;
		while (!file.eof())
		{
			getline(file, tmp);
			if (tmp.substr(0,tmp.find(" ")) == "Ordinary_order")
			{
				//tmp.erase(tmp.begin(),tmp.end()-1);
				obj = new Ordinary_order();
				((Ordinary_order*)obj)->load(tmp);
				add_order(obj);
			}
			else if (tmp.substr(0, tmp.find(" ")) == "Express_Order")
			{
				obj = new Express_Order();
				((Express_Order*)obj)->load(tmp);
				add_order(obj);
			}
			else if (tmp.substr(0, tmp.find(" ")) == "Insured_order")
			{
				Order* obj = new Insured_order();
				((Insured_order*)obj)->load(tmp);
				add_order(obj);
			}
			//file.get();
		}
		file.close();
	}
}
