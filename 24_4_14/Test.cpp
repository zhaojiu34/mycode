#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class OB
{
public:
	void func()
	{
		cout << "void func()" << endl;
	}
};

typedef void(OB::* PtrFunc)();//成员函数指针类型

//int main()
//{
//	// 函数指针
//	// void (*ptr)();
//
//	// 成员函数要加&才能取到函数指针
//	PtrFunc fp = &OB::func;//定义成员函数指针p指向函数func
//
//	OB temp;//定义ob类对象temp
//
//	(temp.*fp)();
//	
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	int GetYear()
//	{
//		return _year;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 重载成全局，无法访问私有成员
//// 1、提供这些成员get和set
//// 2、友元  后面会讲
//// 3、重载为成员函数(一般使用这种)
//
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
////d1-d2
////d1+d2 没有意义
////d1*d2 没有意义
////一个类要重载哪些运算符是看需求，看重载有没有价值和意义
//
//int main()
//{
//	Date d3(2024, 4, 14);
//	Date d4(2024, 4, 15);
//
//	// 显式调用
//	operator==(d3, d4);
//
//	// 直接写，装换调用，编译会转换成operator==(d3, d4);
//	d3 == d4;
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//// d3.Func(d4);
//	//bool Func(const Date& d)
//	//{
//	//	return this->_year == d._year
//	//		&& this->_month == d._month
//	//		&& this->_day == d._day;
//	//}
//
//	// d3.operator==(d4);
//	bool operator==(const Date& d)
//	{
//		return this->_year == d._year
//			&& this->_month == d._month
//			&& this->_day == d._day;
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
//	Date d3(2024, 4, 14);
//	Date d4(2024, 4, 15);
//
//	// 显式调用
//	d3.operator==(d4);
//
//	// 转换调用 等价于d3.operator==(d4);
//	d3 == d4;
//
//	int i = 0, j = 1;
//	bool ret = i == j;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////
// 
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// d1 = d4;
//	// d1 = d2 = d4;
//	// d1 = d1
//	// Date operator=(const Date& d)
//	/*Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}*/
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//		_year = -1;
//		_month = -1;
//		_day = -1;
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
//	Date d1(2024, 4, 14);
//
//	// 拷贝构造
//	// 一个已经存在的对象，拷贝给另一个要创建初始化的对象
//	Date d2(d1);
//	Date d3 = d1;
//
//	Date d4(2024, 5, 1);
//
//	// 赋值拷贝/赋值重载
//	// 一个已经存在的对象，拷贝赋值给另一个已经存在的对象
//	d1 = d4;
//
//	d1 = d2 = d4;
//
//	d1 = d1;
//	
//	int i, j, k;
//	i = j = k = 1;
//
//	return 0;
//}

//Date& func()
//{
//	static Date d(2024, 4, 14);
//	return d;
//}
//// 出了作用域，返回对象还在没有析构，那就可以用引用返回，减少拷贝
//// a、返回对象生命周期到了，会析构，传值返回
//// b、返回对象生命周期没到，不会析构，传引用返回
//
//int main()
//{
//	Date& ref = func();
//	ref.Print();
//
//	return 0;
//}

//Date& func()
//{
//	Date d(2024, 4, 14);
//	//cout << &d << endl;
//	return d;
//}
//
//int fx()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//
//	return a + b + c;
//}
//
//int main()
//{
//	//Date& ref = func();
//	const Date& ref = func();
//	//cout << &ref << endl;
//	fx();
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////
#include"Date.h"

void TestDate1()
{
	Date d1(2024, 4, 14);
	Date d2 = d1 + 30000;
	d1.Print();
	d2.Print();

	Date d3(2024, 4, 14);
	Date d4 = d3 - 5000;
	d3.Print();
	d4.Print();

	Date d5(2024, 4, 14);
	d5 += -5000;
	d5.Print();
}

void TestDate2()
{
	Date d1(2024, 4, 14);
	Date d2 = ++d1;
	d1.Print();
	d2.Print();

	Date d3 = d1++;
	d1.Print();
	d3.Print();

	/*d1.operator++(1);
	d1.operator++(100);
	d1.operator++(0);
	d1.Print();*/
}

void TestDate3()
{
	Date d1(2024, 4, 14);
	Date d2(2034, 4, 14);

	int n = d1 - d2;
	cout << n << endl;

	n = d2 - d1;
}

void TestDate4()
{
	Date d1(2024, 4, 14);
	Date d2 = d1 + 30000;

	// operator<<(cout, d1)
	cout << d1;
	cout << d2;

	cin >> d1 >> d2;
	cout << d1 << d2;
}

void TestDate5()
{
	const Date d1(2024, 4, 14);
	d1.Print();

	//d1 += 100;
	d1 + 100;

	Date d2(2024, 4, 25);
	d2.Print();

	d2 += 100;

	d1 < d2;
	d2 < d1;
}

//int main()
//{
//	// 提高效率输入的效率，竞赛
//	/*ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);*/
//
//	//TestDate4();
//	TestDate5();
//
//	return 0;
//}

class A
{
public:
	// 我们不实现，编译器会自己实现，我们实现了编译器就不会自己实现了
	// 一般不需要我们自己实现
	// 除非不想让别人取到这个类型对象的真实地址
	A* operator&()
	{
		cout << "A* operator&()" << endl;

		return nullptr;
	}

	const A* operator&() const
	{
		cout << "const A* operator&() const" << endl;

		return (const A*)0xffffffff;
	}
private:
	int _a1 = 1;
	int _a2 = 2;
	int _a3 = 3;
};

int main()
{
	A aa1;
	const A aa2;

	cout << &aa1 << endl;
	cout << &aa2 << endl;

	return 0;
}