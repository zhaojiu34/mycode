#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
//class Date
//{
//public:
//
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//};
//
////赋值运算重载成全局函数，注意重载成全局函数是就没有this之指针了，需要给两个参数
//Date& operator=(Date& left, const Date& right)
//{
//	left._year = right._year;
//	left._month = right._month;
//	left._day = right._day;
//
//	return left;
//}

//class Time
//{
//public:
//	Time()
//	{
//		 _hour = 1;
//		 _minute = 1;
//		 _second = 1;
//	}
//
//	Time& operator=(const Time& t)
//	{
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//
//		return *this;
//	}
//
//private:
//	int _hour = 1;
//	int _minute = 1;
//	int _second = 1;
//};
//
//class Date
//{
//private:
//	//基本类型（内置类型）
//	int _year;
//	int _month;
//	int _day;
//
//	//自定义类型
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//}

//如果是栈，这里需要深拷贝解决
//typedef int DataType;
//
//class Stack
//{
//	Stack(int n = 4)
//	{
//		_a = (DataType*)malloc(sizeof(DataType) * n);
//
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_size = 0;
//		_capacity = n;
//	}
//
//	Stack& operator=(const Stack& st)
//	{
//		if (this != &st)
//		{
//			_a = (DataType*)malloc(sizeof(DataType) * st._capacity);
//			if (_a == nullptr)
//			{
//				perror("malloc fail");
//				return;
//			}
//
//			_size = st._size;
//			_capacity = st._capacity;
//		}
//	}
//
//	~Stack()
//	{
//		if (_a)
//		{
//			free(_a);
//			_a = nullptr;
//			_size = _capacity = 0;
//		}
//	}
//private:
//	DataType* _a;
//	int _size;
//	int _capacity;
//};

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
//	//前置++
//	Date& operator++()
//	{
//		_day += 1;
//		return (*this);
//	}
//
//	//后置++
//	//前置++和后置++都是一元运算符，为了让前置++和后置++形成正确的重载
//	//c++规定：后置++重载时多加一个int类型，但是调用函数时不用传递，编译器自动传递
//	//注意：后置++是先使用后+1，因此需要返回+1之后的旧值，所以需要先将this保存一份，在让this+1
//	//而tmp是临时对象，只能是传值返回，不能用引用
//
//	Date& operator++(int)
//	{
//		Date tmp = *this;
//		_day += 1;
//
//		return tmp;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	Date d1(2022, 1, 13);
//
//	d = d1++;
//	d = ++d1;
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
//	}
//
//	//void Print(Date* const this)  本身指向的对象是不能修改的，但是指向的内容可以改 
//	void Print()
//	{
//		cout << "年" << _year << endl;
//		cout << "月" << _month << endl;
//		cout << "日" << _day << endl;
//	}
//
//	//void Print(const Date* const this)  本身指向的对象 和 指向的对象的内容 都不可以修改
//	void Print()const
//	{
//		cout << "年" << _year << endl;
//		cout << "月" << _month << endl;
//		cout << "日" << _day << endl;
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
//	Date d1(2024, 4, 28);
//	d1.Print();
//
//	Date d2(2024, 4, 27);
//	d2.Print();
//
//	return 0;
//}

class Date
{
public:
	Date* operator&()
	{
		return this;
	}

	const Date* operator&()const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};