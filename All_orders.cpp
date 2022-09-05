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
	/*if (((Ordinary_order*)(*(i)))->get_order_time() == critery)
	{
		(*(i))->show();
	}
	else if (((Express_Order*)(*(i)))->get_order_time() == critery)
	{
		(*(i))->show();
	}
	else if (((Insured_order*)(*(i)))->get_order_time() == critery)
	{
		(*(i))->show();
	}*/
	for (i = syst.begin(); i != syst.end(); i++)
	{
		(*(i))->show();
	}
}

void All_orders::search_by_type(string type)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->type() == type)
		{
			(*(i))->show();
		}
		else if (((Express_Order*)(*(i)))->type() == type)
		{
			(*(i))->show();
		}
		else if (((Insured_order*)(*(i)))->type() == type)
		{
			(*(i))->show();
		}
	}
}

void All_orders::search_by_date(Date critery)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		//if (((Ordinary_order*)(*(i)))->get_order_date() == Date(atoi(critery.substr(0, critery.find(".")).c_str()), atoi(critery.substr(critery.find(".")+1, critery.find(".")).c_str()), atoi(critery.substr(critery.find(".") + 1, 2).c_str())))
		if (((Ordinary_order*)(*(i)))->get_order_date() == critery)
		{
			(*(i))->show();
		}
		else if(((Express_Order*)(*(i)))->get_order_date() == critery)
		{
			(*(i))->show();
		}
		else if (((Insured_order*)(*(i)))->get_order_date() == critery)
		{
			(*(i))->show();
		}
	}

}
void All_orders::search_by_time(Time critery)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->get_order_time() == critery)
		{

			(*(i))->show();
		}
		else if (((Express_Order*)(*(i)))->get_order_time() == critery)
		{
			(*(i))->show();
		}
		else if (((Insured_order*)(*(i)))->get_order_time() == critery)
		{
			(*(i))->show();
		}
	}

}

void All_orders::search_by_description(string description)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->get_description() == description)
		{
			(*(i))->show();
		}
		else if (((Express_Order*)(*(i)))->get_description() == description)
		{
			(*(i))->show();
		}
		else if (((Insured_order*)(*(i)))->get_description() == description)
		{
			(*(i))->show();
		}
	}
}

void All_orders::search_by_price(float price)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Ordinary_order*)(*(i)))->get_price() == price)
		{
			(*(i))->show();
		}
		else if (((Express_Order*)(*(i)))->get_price() == price)
		{
			(*(i))->show();
		}
		else if (((Insured_order*)(*(i)))->get_price() == price)
		{
			(*(i))->show();
		}
	}
}

void All_orders::search_by_courier(string courier)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Express_Order*)(*(i)))->get_courier() == courier)
		{
			(*(i))->show();
		}
	}
}

void All_orders::search_by_days_to_deliver(int days_to_deliver)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if (((Express_Order*)(*(i)))->get_days_to_deliver() == days_to_deliver)
		{
			(*(i))->show();
		}
	}
}

void All_orders::search_by_name_company(string name_company)
{
	if (((Insured_order*)(*(i)))->get_name_company() == name_company)
	{
		(*(i))->show();
	}
}

void All_orders::search_by_days_money_amountr(float money_amount)
{
	if (((Insured_order*)(*(i)))->get_money_amount() == money_amount)
	{
		(*(i))->show();
	}
}

void All_orders::sort_by_number()
{
	multiset<Order*, Compire_by_num>tmp;
	multiset<Order*, Compire_by_num>::iterator itm = tmp.begin();

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

void All_orders::sort_by_date()
{
	multiset<Order*, Compire_by_date>tmp;
	multiset<Order*, Compire_by_date>::iterator itm = tmp.begin();
	
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
	
void All_orders::sort_by_time()
{
	multiset<Order*, Compire_by_time>tmp;
	multiset<Order*, Compire_by_time>::iterator itm = tmp.begin();


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
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->get_number() == number)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			break;
		}
	}
}

void All_orders::del_by_date(Date critery)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->get_order_date() == critery)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			break;
		}
	}
}

void All_orders::del_by_time(Time critery)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((*(i))->get_order_time() == critery)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			break;
		}
	}
}

void All_orders::del_by_description(string description)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((((Ordinary_order*)(*(i))))->get_description() == description)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
			break;
		}
	}
}

void All_orders::del_by_price(float price)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		if ((((Ordinary_order*)(*(i))))->get_price() == price)
		{
			vector<Order*>::iterator del = i;
			i++;
			syst.erase(del);
		}
	}
}

void All_orders::del_by_type(string type)
{
	for (i = syst.begin(); i != syst.end(); i++)
	{
		vector<Order*>::iterator del = i;
		i++;
		if ((((Ordinary_order*)(*(del))))->type() == type)
		{
			syst.erase(del);
			break;
		}
	}
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
			if (tmp.substr(0,tmp.find("Ordinary_order")+14) == "Ordinary_order")
			{
				//tmp.erase(tmp.begin(),tmp.end()-1);
				obj = new Ordinary_order();
				obj->load(file);
				add_order(obj);
			}
			else if (tmp == "Express_Order")
			{
				obj = new Express_Order();
				obj->load(file);
				add_order(obj);

			}
			else if (tmp == "Insured_order")
			{
				Order* obj = new Insured_order();
				obj->load(file);
				add_order(obj);
			}
			file.get();
		}
		file.close();
	}
}
