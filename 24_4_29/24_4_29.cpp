#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

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
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	//��ʼ��������ʼ��������
//	//�����Ͽ������Ϊÿ�������ж���ĵط�
//	//��ʼ������͹��캯�����Ի����ã�������д��ʼ����������ó�ʼ������
//	B(int a, int ref)
//		:_aobj(a)
//		,_ref(ref)
//		,_n(10)
//	{}
//
//private:
//	//������û�п��ռ�
//	A _aobj;
//	int& _ref;
//	const int _n;
//};

//��ʼ��������д��д��ÿ����Ա��������һ��
//1�Զ������ͣ�����Ĭ�Ϲ���
//2�������ͣ���������
//C11�в����ȱʡֵ����Ϊ��ʼ������׼����

//class Time
//{
//public:
//	//���߳�ʼ���������ߺ�����
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int day)
//	{}
//
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa(1);//��ʼ������
//
//	A aa1(aa);//��������
//
//	//��ʽ����ת����A֧����һ��int���͹��죬�������Ĺ���֧����ʽ����ת��
//	A aa3 = 3;
//	//A aa5 = "11111" //error:�����ַ�����aa5�ǿɶ���д��
//
//	//A& aa4 = 3;//error����ʱ�������г���
//	const A& aa4 = 3;
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//typedef A STDateType;
//
//class Stack
//{
//public:
//	void Push(A aa)
//	{
//		//......
//	}
//private:
//	STDateType* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st1;
//
//	//�ȴ���һ��A�������ٰ�����������赽ջ��
//	A a(1);
//	st1.Push(a);
//
//	//ֱ����ʽת��
//	st1.Push(1);
//	
//	return 0;
//}

////��������캯��
//class A
//{
//public:
//	A(int a1, int a2)
//		:_a1(a1)
//		,_a2(a2)
//	{}
//
//private:
//	int _a1;
//	int _a2;
//};
//
//int main()
//{
//	A aa1(1, 2);//���캯��
//
//	//�߼��͵���������ת������
//	//��ʽ����ת��
//	A aa2 = { 1,2 };//��ʽ����ת��
//
//	return 0;
//}

////explicit���ι��캯������ֹ����ת��
//class A
//{
//public:
//	explicit A(int a)
//		:_a(a)
//	{}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1 = 2;
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//
//	~A()
//	{
//		--_scount;
//	}
//private:
//	//�������Ը�ȱʡֵ
//	int _a1;//��ͨ��Ա����
//	int _a2;
//	//��̬��Ա����
//	//���߳�ʼ��������ʼ�������ǳ�ʼ�����󣬾�̬��Ա���ٶ������棬���߳�ʼ������
//
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//int main()
//{
//	A aa1;
//	
//	cout << sizeof(aa1) << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		++ _scount;
//	}
//
//	A(const A& a)
//	{
//		++_scount;
//	}
//
//	~A()
//	{
//		--_scount;//���������ʵʱ�������ڶ��ٸ�����û�о���һ�������˶��ٸ�����
//	}
//
//	static int GetAcout()
//	{
//		return _scount;
//	}
//
//private:
//	int _a;
//	static int _scount;//��̬��Ա����ֻ��ͨ����̬��������
//};
//
//int A::_scount = 0;
//
//int main()
//{
//	cout << A::GetAcout() << endl;
//
//	A aa;
//	A aa1;
//	A aa2 = aa1;
//
//	cout << A::GetAcout() << endl;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//
//	//d1<<cout; -> d1.operator<<(&d1,cout); �����ϳ������
//	//��Ϊ��Ա������һ������һ�������ص�this������d1�������<<���
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month <<"-" << d._day << endl;
//
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year >> d._month >> d._day;
//
//	return _cin;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//
//	return 0;
//}

//class Time
//{
//	//����������Ϊʱ�������Ԫ�࣬�����������п���ֱ�ӷ���Time��
//	friend class Date;
//
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour)
//		,_minute(minute)
//		,_second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//
//	void SetTime(int hour = 0, int minute = 0, int second = 0)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};

//class A
//{
//public:
//	class B //B��������A����Ԫ
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;
//			cout << a.h << endl;
//		}
//	};
//private:
//	static int k;
//	int h;
//};
//
//int A::k = 1;
//
//int main()
//{
//	A::B b;
//	b.foo(A());
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{

		cout << "A(int a)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};

class Solution
{
public:
	int Sum_solution(int n)
	{
		//....
		return n;
	}

};

int main()
{
	A aa1;//�����������������ǵ�ǰ������

	//�����������������Ϊ�޷������Ǻ����������Ƕ�����
	//A aa1();

	//�������ǿ�����������������������������ص���ǲ���ȡ����
	//���������������ھ�ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
	A();

	A aa2(2);

	//���������������ĳ����¾ͺܺ���
	Solution().Sum_solution(10);

	return 0;
}