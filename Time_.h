#pragma once
#include <time.h>
#include <iostream>
#include <cstring>
using namespace std;
class Time
{
private:
	int hour;
	int minutes;
	int seconds;
	char format[4]; //am/pm and utc
public:
	Time(); //current time
	Time(int hour, int minutes, int seconds, const char*format = "utc");
	Time(const Time& obj);
	~Time();

	//----------------------------------------------------------------------

	void setHour(int hour);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(const char* format); // !!! to update time by the new format: utc
	const char* getFormat(); //utc/am/pm

	//-----------------------------------------------------------------------

	bool valid(); //time check
	void tickTime(); //every tick add one second
	void backTime();
	void showTime(); //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time& obj)const&;
	bool operator != (const Time& obj)const&;
	bool operator > (const Time& obj)const&;
	bool operator < (const Time& obj)const&;
	bool operator >= (const Time& obj)const&;
	bool operator <= (const Time& obj)const&;

	//--------- Assignment operators ---------
	Time& operator = (const Time& obj);
	Time& operator += (int n);
	Time& operator -= (int n);

	//--------- Arithmetic operators ---------
	Time operator + (int n);
	Time operator - (int n);

	Time& operator -- ();
	Time& operator -- (int n);
	Time& operator ++ ();
	Time& operator ++ (int n);

	friend ostream& operator << (ostream& os, const Time& t);
	friend istream& operator >> (istream& is, Time& t);

};

