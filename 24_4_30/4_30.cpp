#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

bool Date::CheckDay()
{
	if (_month < 1 || _month > 12 || _day <0 || _day >GetMonthDay(_year, _month))
		return false;

	return true;
}

bool Date::operator<(const Date d)const
{
	if (_year < d._year)
	{
		return true;
	}

	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}

	return false;
}
bool Date::operator<=(const Date d)const
{
	return ((*this) < d) || ((*this) == d);
}
bool Date::operator==(const Date d)const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator>=(const Date d)const
{
	return !((*this) < d);
}
bool Date::operator>(const Date d)const
{
	return !((*this) <= d);
}
bool Date::operator!=(const Date d)const
{
	return !((*this) == d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return (*this) -= (-day);
	}

	_day += day;

	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}

	return (*this);
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;

	return tmp;
}

Date& Date::operator-=(int day)
{

	if (day < 0)
	{
		return (*this) += (-day);
	}

	_day -= day;

	while (_day <= 0)
	{
		_month--;
		if (_month < 0)
		{
			_month = 12;
			_year--;
		}

		_day += GetMonthDay(_year, _month);
	}

	return (*this);
}
Date Date::operator-(int day)
{
	Date tmp = (*this);
	tmp -= day;

	return (*this);
}

Date Date::operator++()
{
	(*this) += 1;

	return  (*this);
}
Date Date::operator++(int)
{
	Date tmp = (*this);
	(*this) += 1;

	return tmp;
}

Date Date::operator--()
{
	(*this) -= 1;

	return  (*this);
}
Date Date::operator--(int)
{
	Date tmp = (*this);
	(*this) -= 1;

	return tmp;
}

int Date::operator-(const Date d)
{
	int n = 0;
	int flag = 1;

	//假设this大，d小
	//d1大，d2小
	Date d1 = *this;
	Date d2 = d;

	if (d1 < d2)
	{
		flag = -1;
		d1 = d;
		d2 = *this;
	}

	while (d1 != d2)
	{
		++n;
		++d2;
	}

	return n * flag;
}

ostream& operator<<(ostream& out, const Date d)
{
	out << "年" << d._year << "月" << d._month << "日" << d._day << endl;

	return out;
}
istream& operator>>(istream& in, const Date d)
{
	in >> d._year >> d._month >> d._day;

	return in;
}
