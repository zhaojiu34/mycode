#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class Person
//{
//public:
//	void PrintPersonInfo();
//
//	const char* _name;
//	const char* _gender;
//	int _age;
//
//};
//
//����ָ��PrintPersonInfo������Person������
//void Person::PrintPersonInfo()
//{
//	cout << "_name" << " " << "_gender" << " " << " age" << endl;
//
//}
//
//int main()
//{
//	Person man;
//	man._name = "zhangsan";
//	man._gender = "man";
//	man._age = 30;
//	man.PrintPersonInfo();
//
//	return 0;
//}

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << "_a" << endl;
//	}
//
//private:
//	char _a;
//};

////���м��г�Ա�������г�Ա����
//class A1
//{
//public:
//	void f1(){}
//private:
//	int _a;
//};
//
////���н��г�Ա����
//class A2
//{
//public:
//	void f2(){}
//
//};
//
////����ʲô��û�п���
//class A3
//{
//
//};
//
//int main()
//{
//	//�����Ƕ�����˻���û�ж���ã�
//	A3 aa1;
//	A3 aa2;
//
//
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	return 0;
//}

class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//void Print(Date* this)
	void Print()
	{
		cout << "this->_year" << "-" << "this->_month" << "-" << "this->_day" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1, d2;
	d1.Init(2024, 4, 5);
	d1.Print();

	d2.Init(2023, 4, 4);
	d2.Print();

	return 0;
}