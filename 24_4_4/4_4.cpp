#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int DataType;

//struct Stack
//{
//	void Init(int n = 4)
//	{
//		a = nullptr;
//		size = capacity = n;
//	}
//
//	void Push(DataType x)
//	{
//		if (size == capacity)
//		{
//			int newCapacity = capacity * 2;
//			int* tmp = (int*)realloc(a,sizeof(int) * newCapacity);
//			if (tmp == nullptr)
//			{
//				perror("realloc fail");
//				return;
//			}
//
//			a = tmp;
//			capacity = newCapacity;
//		}
//
//		a[size++] = x;
//	}
//
//	DataType Top()
//	{
//		return a[size - 1];
//
//	}
//
//	void Destroy()
//	{
//		free(a);
//		a = nullptr;
//		size = capacity = 0;
//	}
//
//	DataType* a;
//	int capacity;
//	int size;
//};

////声明和定义全部放在类体中
////人
//class Person
//{
////公开
//public:
//	//显示基本信息
//	void showInfo()
//	{
//		//......
//	}
//public:
//	char* name;
//	char* sex;
//	int age;
//};

class Date
{
public:
	//成员函数
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:

	//成员变量
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d;
	d.Init(2024, 4, 4);
	d.Print();

	return 0;
}