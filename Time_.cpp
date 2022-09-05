#include "Time_.h"
#include <iostream>
using namespace std;

Time::Time()
{
	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);
	strcpy_s(this->format, "utc");
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
}

Time::Time(int hour, int minutes, int seconds, const char * format)
{
	strcpy_s(this->format, format);
	if(strcmp(this->format, "utc") == 0 && hour > 0 && hour < 25) this->hour = hour;
	else if (strcmp(this->format, "utc") != 0 && hour > 0 && hour < 13) this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::Time(const Time & obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	strcpy_s(this->format, obj.format);
}

Time::~Time()
{

}

void Time::setHour(int hour)
{
	if (strcmp(format, "utc") == 0) {
		if (hour > 0 && hour < 25) this->hour = hour;
	}
	else {
		if (hour < 13) {
			this->hour = hour;
			strcpy_s(this->format, "am");
		}
		else {
			this->hour = hour - 12;
			strcpy_s(this->format, "pm");
		}
	}
}

int Time::getHour()const
{
	return this->hour;
}

void Time::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes < 60) this->minutes = minutes;
}

int Time::getMinutes()const
{
	return this->minutes;
}

void Time::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds < 60) this->seconds = seconds;
}

int Time::getSeconds()const
{
	return this->seconds;
}

void Time::setFormat(const char * format)
{
	if (strcmp(format, "utc") == 0) {
		if (strcmp(this->format, "pm") == 0) this->hour += 12;
		strcpy_s(this->format, format);
	}
	else if (strcmp(format, "am") == 0 || strcmp(format, "pm") == 0) {
		strcpy_s(this->format, format);
		if (this->hour > 12) this->hour -= 12;
	}
}

const char * Time::getFormat()
{
	return this->format;
}

bool Time::valid()
{
	if (strcmp(this->format, "utc") == 0) {
		if (this->hour > 0 && this->hour < 25 && this->minutes >= 0 && this->minutes < 60 && this->seconds >= 0 && this->seconds < 60) return true;
	}
	else if(strcmp(this->format, "am") == 0 || strcmp(this->format, "pm") == 0){
		if (this->hour > 0 && this->hour < 13 && this->minutes >= 0 && this->minutes < 60 && this->seconds >= 0 && this->seconds < 60) return true;
	}
	else return false;
}

void Time::tickTime()
{
	this->seconds++;
	if (this->seconds >= 60) {
		this->minutes++;
		this->seconds = 0;
	}
	if (this->minutes >= 60) {
		this->hour++;
		this->minutes = 0;
	}
	if (this->hour >= 24 && strcmp(this->format, "utc") == 0) this->hour = 1;
	else if (this->hour >= 12 && strcmp(this->format, "am") == 0 || this->hour >= 12 && strcmp(this->format, "pm") == 0) this->hour = 1;
}

void Time::backTime()
{
	this->seconds--;
	if (this->seconds < 0) {
		minutes--;
		seconds = 59;
	}
	else if (this->minutes < 0) {
		hour--;
		minutes = 59;
	}
	else if (this->hour < 1 && strcmp(this->format, "utc") == 0) {
		this->hour = 24;
	}
	else {
		this->hour = 12;
	}
}

void Time::showTime()
{
	if (strcmp(this->format, "utc") == 0) cout << this->hour / 10 << this->hour % 10 << ":" << this->minutes / 10 << this->minutes % 10 << endl;
	else if (strcmp(this->format, "am") == 0) cout << this->hour / 10 << this->hour % 10 << " AM " << this->minutes / 10 << this->minutes % 10 << endl;
	else if (strcmp(this->format, "pm") == 0) cout << this->hour / 10 << this->hour % 10 << " PM " << this->minutes / 10 << this->minutes % 10 << endl;
	cout << "Seconds: " << this->seconds / 10 << this->seconds % 10 << endl; //I printed it also for myselve
}

bool Time::operator==(const Time & obj)const&
{
	if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds == obj.seconds && strcmp(this->format, obj.format) == 0) return true;
	else if (strcmp(this->format, "utc") == 0 && strcmp(obj.format, "pm") == 0) {
		if (this->hour == obj.hour + 12 && this->minutes == obj.minutes && this->seconds == obj.seconds) return true;
	}
	else if (strcmp(this->format, "pm") == 0 && strcmp(obj.format, "utc") == 0) {
		if (this->hour + 12 == obj.hour && this->minutes == obj.minutes && this->seconds == obj.seconds) return true;
	}
	return false;
}
bool Time::operator!=(const Time & obj)const&
{
	return !(*this == obj);
}

bool Time::operator>(const Time & obj)const&
{
	if (strcmp(this->format, obj.format) == 0 && strcmp(this->format, "utc") == 0) {
		if (this->hour > obj.hour) return true;
		else if (this->hour == obj.hour && this->minutes > obj.minutes) return true;
		else if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds > obj.seconds) return true;
		else return false;
	}
	else if (strcmp(this->format, "am") == 0 && strcmp(obj.format, "pm") == 0) return false;
	else if (strcmp(this->format, "pm") == 0 && strcmp(obj.format, "am") == 0) return true;
	else if (strcmp(this->format, "utc") == 0 && strcmp(obj.format, "pm") == 0) {
		if (this->hour > obj.hour + 12) return true;
		else if (this->hour == obj.hour + 12 && this->minutes > obj.minutes) return true;
		else if (this->hour == obj.hour + 12 && this->minutes == obj.minutes && this->seconds > obj.seconds) return true;
		else return false;
	}
	else if (strcmp(this->format, "pm") == 0 && strcmp(obj.format, "utc") == 0) {
		if (this->hour + 12 > obj.hour) return true;
		else if (this->hour + 12 == obj.hour && this->minutes > obj.minutes) return true;
		else if (this->hour + 12 == obj.hour && this->minutes == obj.minutes && this->seconds > obj.seconds) return true;
		else return false;
	}
}

bool Time::operator<(const Time & obj)const&
{
	return !(*this > obj) && *this != obj;
}

bool Time::operator>=(const Time & obj)const&
{
	return *this > obj || *this == obj;
}

bool Time::operator<=(const Time & obj)const&
{
	return *this < obj || *this == obj;
}

Time & Time::operator=(const Time & obj) 
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	strcpy_s(this->format, obj.format);
	return *this;
}

Time & Time::operator+=(int n)
{
	for (int i = 0; i < n; i++)
	{
		tickTime();
	}
	return *this;
}

Time & Time::operator-=(int n)
{
	for (int i = 0; i < n; i++)
	{
		backTime();
	}
	return *this;
}

Time Time::operator+(int n)
{
	Time tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.tickTime();
	}
	return tmp;
}

Time Time::operator-(int n)
{
	Time tmp = *this;
	for (int i = 0; i < n; i++)
	{
		tmp.backTime();
	}
	return tmp;
}

Time & Time::operator--()
{
	this->backTime();
	return *this;
}

Time & Time::operator--(int n)
{
	Time tmp = *this;
	tmp.backTime();
	return tmp;
}

Time & Time::operator++()
{
	this->tickTime();
	return *this;
}

Time & Time::operator++(int n)
{
	Time tmp = *this;
	tmp.tickTime();
	return tmp;
}

ostream & operator<<(ostream & os, const Time & t)
{
	if (strcmp(t.format, "utc") == 0) os << t.hour / 10 << t.hour % 10 << ":" << t.minutes / 10 << t.minutes % 10;
	else if (strcmp(t.format, "am") == 0) os << t.hour / 10 << t.hour % 10 << " AM " << t.minutes / 10 << t.minutes % 10;
	else if (strcmp(t.format, "pm") == 0) os << t.hour / 10 << t.hour % 10 << " PM " << t.minutes / 10 << t.minutes % 10;
	os << ":" << t.seconds / 10 << t.seconds % 10;
	return os;
}

istream & operator>>(istream & is, Time & t)
{
	char tmp[50] = "";
	do
	{
		cout << "Input seconds >> minutes >> hours\n";
		is >> t.seconds >> t.minutes >> t.hour;
		/*is.get(); is.getline(tmp, 50);
		strcpy_s(t.format, 50, tmp);*/
	} while (!(t.valid()));
	return is;
}
