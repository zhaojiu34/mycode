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
////��ֵ�������س�ȫ�ֺ�����ע�����س�ȫ�ֺ����Ǿ�û��thisָ֮���ˣ���Ҫ����������
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
//	//�������ͣ��������ͣ�
//	int _year;
//	int _month;
//	int _day;
//
//	//�Զ�������
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

//�����ջ��������Ҫ������
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
//	//ǰ��++
//	Date& operator++()
//	{
//		_day += 1;
//		return (*this);
//	}
//
//	//����++
//	//ǰ��++�ͺ���++����һԪ�������Ϊ����ǰ��++�ͺ���++�γ���ȷ������
//	//c++�涨������++����ʱ���һ��int���ͣ����ǵ��ú���ʱ���ô��ݣ��������Զ�����
//	//ע�⣺����++����ʹ�ú�+1�������Ҫ����+1֮��ľ�ֵ��������Ҫ�Ƚ�this����һ�ݣ�����this+1
//	//��tmp����ʱ����ֻ���Ǵ�ֵ���أ�����������
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
//	//void Print(Date* const this)  ����ָ��Ķ����ǲ����޸ĵģ�����ָ������ݿ��Ը� 
//	void Print()
//	{
//		cout << "��" << _year << endl;
//		cout << "��" << _month << endl;
//		cout << "��" << _day << endl;
//	}
//
//	//void Print(const Date* const this)  ����ָ��Ķ��� �� ָ��Ķ�������� ���������޸�
//	void Print()const
//	{
//		cout << "��" << _year << endl;
//		cout << "��" << _month << endl;
//		cout << "��" << _day << endl;
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