#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//class Date
//{
//public:
//	//����
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//��ֵ����ʱ�����Զ������ͻ���ÿ�������
//	//���������ÿ������죬���ֽ������
//	//����ַ(��ʱ�����ǿ������죬ֻ�ǹ��캯����һ��������ʽ)
//	Date(Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//
//	//���������ã��������죩
//	/*Date(const Date& d)
//	{
//		d._day = _day;
//		d._month = _month;
//		d._year = _year;
//	}*/
//
//	Date(const Date& d)
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
//
//int main()
//{
//	Date d1;//����
//	Date d2(&d1);//Ҳ�ǹ���
//
//	Date d3(d1);//��������
//	Date d4 = d1;//�����������һ��д��
//
//	return 0;
//}

//class Time
//{
//public:
//
//	Time(int hour = 0, int minute = 0, int second = 0)
//	{
//		_hour = hour;
//		_minute = minute;
//		_second = second;
//	}
//
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	Date d2 = d1;
//
//	return 0;
//}

#include <stdlib.h>

//typedef int SLType;
//
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		SLType* tmp = (SLType*)malloc(sizeof(SLType) * n);
//		if (tmp == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_a = tmp;
//		_capacity = n;
//		_size = 0;
//	}
//	void Push(SLType x)
//	{
//		_a[_size++] = x;
//	}
//
//	//���
//	Stack(const Stack& st)
//	{
//		_a = (SLType*)malloc(sizeof(SLType) * st._capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return ;
//		}
//		_capacity = st._capacity;
//		_size = st._size;
//
//		memcpy(_a, st._a, sizeof(SLType) * st._size);
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
//	SLType* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//	st1.Push(4);
//
//	Stack st2 = st1;
//
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
	{
		cout << "Date(int,int,int)" << this << endl;
	}

	Date(const Date& d)
	{
		cout << "Date(const Date& d):" << this << endl;
	}

	~Date()
	{
		cout << " ~Date()" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

Date Test(Date d)
{
	Date temp(d);

	return temp;
}

int main()
{
	Date d1(2024, 4, 23);

	Test(d1);

	return 0;
}