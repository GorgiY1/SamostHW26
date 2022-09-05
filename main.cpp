#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
#include"Order.h"
#include"Ordinary_order.h"
#include"Express_Order.h"
#include"All_orders.h"
#include"Order_exceptions.h"
using namespace std;

int Order :: amount = 0;

int main()
{
	setlocale(0, "ru");

	try
	{
	All_orders allOrd;

	Ordinary_order ord(Date(2025, 12, 18), Time(23, 59, 5), "meat", 85);
	allOrd.add_order(&ord);
	Express_Order d(Date(2028, 15, 12), Time(23, 57, 5), "milk", 45, "pit", 2);
	Insured_order d2(Date(2027, 15, 12), Time(23, 56, 5), "bread", 5, "MeastExcpress", 500);
	allOrd.add_order(&d);
	allOrd.add_order(&d2);

	/*Ordinary_order ord(Date(2025, 12, 18), Time(18, 59, 5), "ajhf", 85);
		ord.set_description("kjhf");
		ord.show();
		allOrd.add_order(&ord);*/
	
	int number = 0;
	Date order_date = Date(0, 0, 0);
	Time order_time = Time(0, 0, 0);
	string description = "";
	float price = 0;
	string courier = "";
	int days_to_deliver = 0;
	string name_company = "";
	float money_amount = 0;
	
	string type = "";

	int menu = 0;
	int type_menu = 0;
	do
	{
		cout << "1. Add order: \n";
		cout << "2. Show all orders: \n";
		cout << "3. Search the order by fields: \n";
		cout << "4. Sort orders by fields:\n";
		cout << "5. Deleting orders by fields:\n";
		cout << "6. Save to file:\n";
		cout << "7. Load from file:\n";

		/*cout << "6. show all users\n";
		cout << "7. Get edition\n";*/
		cout << "0. Exit\n";
		cin >> menu;

		switch (menu)
		{
		case 1:

			cout << "input type Ordinary_order, Express_Order, or Insured_order for addind: ";
			cin >> type;

			cout << "\ninput date: ";
			cin >> order_date;
			cout << "\ninput time: ";
			cin >> order_time;
			cout << "\ninput description: ";
			cin.ignore();
			getline(cin, description);
			cout << "\ninput price: ";
			cin >> price;

			if (type == "Ordinary_order")
			{
				allOrd.add_order(new Ordinary_order(order_date, order_time, description, price));
				allOrd.show_syst();
				break;
			}
			if (type == "Express_Order")
			{
				cout << "\ninput courier name: ";
				cin >> courier;
				cout << "\ninput days_to_deliver: ";
				cin >> days_to_deliver;

				allOrd.add_order(new Express_Order(order_date, order_time, description, price, courier, days_to_deliver));
				allOrd.show_syst();
				break;
			}
			if (type == "Insured_order")
			{
				string name_company = "";
				float money_amount = 0;
				cout << "\ninput name_company: ";
				cin >> name_company;
				cout << "\n money_amount: ";
				cin >> money_amount;

				allOrd.add_order(new Insured_order(order_date, order_time, description, price, name_company, money_amount));
				allOrd.show_syst();
				break;
			}
		case 2:
			allOrd.show_syst();
			break;
		case 3:
			do
			{
				cout << "1. search_by_date: \n";
				cout << "2. search_by_time: \n";
				cout << "3. search_by_description: \n";
				cout << "4. search_by_price: \n";
				cout << "5. search_by_courier: \n";
				cout << "6. search_by_days_to_deliver: \n";
				cout << "7. search_by_name_company: \n";
				cout << "8. search_by_days_money_amount: \n";
				cout << "9. search_by_type: \n";
				cout << "0. Exit from the menu for searching: \n";

				cout << "input category sort, by this changes: ";
				cin >> type_menu;
				switch (type_menu)
				{
				case 1:
					cout << "Input search date: \n";
					cin >> order_date;
					allOrd.search_by_date(order_date);
					type_menu = 0;
					break;
				case 2:
					cout << "Input search time: \n";
					cin >> order_time;
					allOrd.search_by_time(order_time);
					type_menu = 0;
					break;
				case 3:
					cout << "Input search description: \n";
					cin >> description;
					allOrd.search_by_description(description);
					type_menu = 0;
					break;
				case 4:
					cout << "Input search price: \n";
					cin >> price;
					allOrd.search_by_price(price);
					type_menu = 0;
					break;
				case 5:
					cout << "Input search courier: \n";
					cin >> courier;
					allOrd.search_by_courier(courier);
					type_menu = 0;
					break;
				case 6:
					cout << "Input search days_to_deliver: \n";
					cin >> days_to_deliver;
					allOrd.search_by_days_to_deliver(days_to_deliver);
					type_menu = 0;
					break;
				case 7:
					cout << "Input search name_company: \n";
					cin >> name_company;
					allOrd.search_by_name_company(name_company);
					type_menu = 0;
					break;
				case 8:
					cout << "Input search money_amount: \n";
					cin >> money_amount;
					allOrd.search_by_days_money_amountr(money_amount);
					type_menu = 0;
				case 9:
					cout << "Input search type: \n";
					cin >> name_company;
					allOrd.search_by_type(name_company);
					type_menu = 0;
					break;
					
				default:
					break;
				}
			} while (type_menu != 0);
			break;
		case 4:
			do
			{
				cout << "1. sort_by_date: \n";
				cout << "2. sort_by_time: \n";
				cout << "3. sort_by_description: \n";
				cout << "4. sort_by_price: \n";
				cout << "5. sort_by_number: \n";
				cout << "6. sort_by_priority: \n";
				cout << "0. Exit from the menu for searching: \n";

				cout << "input category sort, by this changes: ";
				cin >> type_menu;
				switch (type_menu)
				{
				case 1:
					allOrd.sort_by_date();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 2:
					allOrd.sort_by_time();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 3:
					allOrd.sort_by_description();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 4:
					allOrd.sort_by_price();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 5:
					allOrd.sort_by_number();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 6:
					allOrd.sort_by_priority();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				default:
					break;
				}
			} while (type_menu != 0);
			break;
		case 5:
			do
			{
				cout << "1. del_by_date: \n";
				cout << "2. del_by_time: \n";
				cout << "3. del_by_description: \n";
				cout << "4. del_by_price: \n";
				cout << "5. del_by_number: \n";
				cout << "6. del_by_type: \n";
				cout << "0. Exit from the menu for searching: \n";

				cout << "input category sort, by this changes: ";
				cin >> type_menu;
				switch (type_menu)
				{
				case 1:
					cout << "Input remove date: \n";
					cin >> order_date;
					allOrd.del_by_date(order_date);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 2:
					cout << "Input remove time: \n";
					cin >> order_time;
					allOrd.del_by_time(order_time);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 3:
					cout << "Input remove description: \n";
					cin >> description;
					allOrd.del_by_description(description);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 4:
					cout << "Input remove price: \n";
					cin >> price;
					allOrd.del_by_price(price);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 5:
					cout << "Input remove number: \n";
					cin >> number;
					allOrd.del_by_number(number);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 6:
					cout << "Input remove type: \n";
					cin >> description;
					allOrd.del_by_type(description);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				default:
					break;
				}
			} while (type_menu != 0);
			
			break;

		case 6:
			allOrd.save("orders"); // save to file by file name (create name)
			break;
		case 7:
			allOrd.load("orders"); // load from file by file name
			break;
		default:
			break;
		}
	} while (menu != 0);

	/*ofstream file("orders.txt")
		if (file.is_open())
		{
			d.save(file);
		}
	ifstream file("orders.txt");

	if (file.is_open())
	{
		d2.load(file);
	}

	file.close();
	d2.show();*/

	}
	catch (Order_exceptions* exc)
	{
		exc->show_message();
	}

	return 0;
}