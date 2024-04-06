#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <stdlib.h>


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << "_month" << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	////1.无参构造函数
//	//Date()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	////2.有参函数
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	//
//	//3.全缺省函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" <<_month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Time
//{
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//
//private:
//	//内置类型
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
//	
//	return 0;
//}

class Stack
{
public:

	Stack()
	{
		_a = (int*)malloc(sizeof(int) * 4);

		if (_a == nullptr)
		{
			perror("malloc fail");
			return;
		}
		_top = 0;
		_capacity = 4;
	}

	void Push(int x)
	{
		if (_capacity == _top)
		{
			int newCapacity = 2 * _capacity;
			int* tmp = (int*)realloc(_a,sizeof(int) * newCapacity);

			if(tmp == nullptr)
			{
				perror("tmp realloc fail");
				return;
			}

			_a = tmp;
			_capacity = newCapacity;
		}

		_a[_top++] = x;
	}

	void Pop()
	{
		_top--;
	}

	int Top()
	{
		return _a[_top - 1];
	}

	bool Empty()
	{
		return _top == 0;
	}

	/*void Destroy()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}*/

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;

	}
private:
	int* _a;
	int _top;
	int _capacity;
};

class MyQueue
{

	Stack _popst;
	Stack _pushst;
};

int main()
{
	MyQueue q;

	return 0;
}