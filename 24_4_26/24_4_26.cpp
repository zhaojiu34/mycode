#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

////.* �÷������ó�Ա����ָ��
//class OB
//{
//public:
//	void func()
//	{
//		cout << "void func()" << endl;
//	}
//};
//
//typedef void(OB::* PtrFunc)();//��Ա����ָ������
//
//int main()
//{
////������ͨ�����������Ϳ��Ա�ʾ������ַ
////��Ա�����ĵ�ַ��������&
//	PtrFunc fp = &OB::func;//�����Ա����ָ��fpָ���Ա����
//
//	OB tmp;
//	(tmp.*fp)();//����func����
//	return 0;
//}


////ȫ�ֵ�opreater==
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
//	//��ֵ����
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
	
	//��ֵ����
	Date& operator==(const Date& d)
	{
		//����д��d1 = d1,������������ַ�ǲ�����ͬ
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;

		}
		return (*this);//*this��d2����mian������ջ�ϣ���������
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