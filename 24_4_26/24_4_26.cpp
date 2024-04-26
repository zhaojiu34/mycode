#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

////.* 用法：调用成员函数指针
//class OB
//{
//public:
//	void func()
//	{
//		cout << "void func()" << endl;
//	}
//};
//
//typedef void(OB::* PtrFunc)();//成员函数指针类型
//
//int main()
//{
////对于普通函数函数名就可以表示函数地址
////成员函数的地址必须是用&
//	PtrFunc fp = &OB::func;//定义成员函数指针fp指向成员函数
//
//	OB tmp;
//	(tmp.*fp)();//调用func函数
//	return 0;
//}


////全局的opreater==
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._day == d2._day
//		&& d1._month == d2._month
//		&& d1._year == d2._year;
//}



//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator==(const Date& d )
//	{
//		return _day == d._day
//			&& _month == d._month
//			&& _year == d._year;
//	}
//
//	private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d1(2023, 4, 23);
//	Date d2(2024, 4, 23);
//
//	cout << (d1 == d2) << endl;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._year;
//	}
//	
//	//赋值重载
//	Date& operator==(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 4, 23);
//	Date d2(2024, 5, 1);
//	Date d3(2023, 4, 20);
//
//	d1 = d2 = d3;
//
//	//int i, j, k;
//	//k = 1;
//	//i = j = k;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	~Date()
//	{
//		_year = _month = _day = -1;
//		cout << "~Date()" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////Date& func()
////{
////	Date d(2024, 4, 23);
////	
////	return d;
////}
//
//Date& func()
//{
//	static Date d(2024, 4, 23);
//
//	return d;
//}
//int main()
//{
//
//	Date& d = func();
//
//	return 0;
//}


class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._year;
	}
	
	//赋值重载
	Date& operator==(const Date& d)
	{
		//避免写出d1 = d1,看两个变量地址是不是相同
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;

		}
		return (*this);//*this是d2，在mian函数的栈上，不会析构
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2024, 4, 23);
	Date d2(2024, 5, 1);
	Date d3(2023, 4, 20);

	d1 = d2 = d3;

	return 0;
}