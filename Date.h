#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear(); 
	int monthDays();  
	void nextDate();  
	void prevDate();  

public:
	 
	Date(); 
	Date(int seconds);
	Date(int year, int month, int day);  
	Date(const Date& obj);  
	~Date(); 

			 
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	const char* getSMonth(const char* lan = "EN")const;
	void setDay(int day);
	int getDay()const;

	bool valid();  
	void showDate();

	//--------- Comparison operators ---------
	bool operator == (const Date&  obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- Assignment operators ---------
	Date& operator = (const Date& obj);
	Date& operator += (int n);
	Date& operator -= (int n);

	//--------- Arithmetic operators ---------
	Date operator + (int n);
	Date operator - (int n);

	friend ostream& operator << (ostream& out,const Date& obj);
	friend istream& operator >> (istream& in, Date& obj);
};

