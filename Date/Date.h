#pragma once
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date d);
	friend istream& operator>>(istream& in, const Date d);
public:
	Date(int year = 1900, int month = 1, int day = 1);

	void Print()
	{
		cout << "年 " << _year << "月 " << _month<<"日 " << _day << endl;
	}

	//得到对应年月的天数
	int GetMonthDay(int year, int month)
	{
		static int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if(month == 2 &&((year%100 != 0&& year%4==0) || (year % 400 == 0)))
			return day[month]+1;
		else
			return day[month];
	}

	bool CheckDay();

	bool operator<(const Date d)const;
	bool operator<=(const Date d)const;
	bool operator==(const Date d)const;
	bool operator>=(const Date d)const;
	bool operator>(const Date d)const;
	bool operator!=(const Date d)const;

	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	Date operator++();
	Date operator++(int);

	Date operator--();
	Date operator--(int);

	int operator-(const Date d);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date d);
istream& operator>>(istream& in, const Date d);
