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
//	//初始化链表：初始化并定义
//	//本质上可以理解为每个对象中定义的地方
//	//初始化链表和构造函数可以混着用，但是能写初始化链表最好用初始化链表
//	B(int a, int ref)
//		:_aobj(a)
//		,_ref(ref)
//		,_n(10)
//	{}
//
//private:
//	//声明，没有开空间
//	A _aobj;
//	int& _ref;
//	const int _n;
//};

//初始化链表不管写不写，每个成员都会先走一遍
//1自定义类型，调用默认构造
//2内置类型，不做处理
//C11中补充的缺省值就是为初始化链表准备的

//class Time
//{
//public:
//	//先走初始化链表，再走函数体
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
//	A aa(1);//初始化构造
//
//	A aa1(aa);//拷贝构造
//
//	//隐式类型转换：A支持用一个int类型构造，单参数的构造支持隐式类型转换
//	A aa3 = 3;
//	//A aa5 = "11111" //error:常性字符串，aa5是可读可写的
//
//	//A& aa4 = 3;//error：临时变量具有常性
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
//	//先创建一个A变量，再把这个变量铺设到栈中
//	A a(1);
//	st1.Push(a);
//
//	//直接隐式转换
//	st1.Push(1);
//	
//	return 0;
//}

////多参数构造函数
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
//	A aa1(1, 2);//构造函数
//
//	//逻辑和单参数类型转换类似
//	//隐式类型转换
//	A aa2 = { 1,2 };//隐式类型转换
//
//	return 0;
//}

////explicit修饰构造函数，禁止类型转换
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
//	//声明可以给缺省值
//	int _a1;//普通成员变量
//	int _a2;
//	//静态成员变量
//	//不走初始化链表，初始化链表是初始化对象，静态成员不再对象里面，不走初始化链表
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
//		--_scount;//有这个就是实时，还存在多少个对象，没有就是一共创建了多少个对象
//	}
//
//	static int GetAcout()
//	{
//		return _scount;
//	}
//
//private:
//	int _a;
//	static int _scount;//静态成员变量只能通过静态函数返回
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
//	//d1<<cout; -> d1.operator<<(&d1,cout); 不符合常规调用
//	//因为成员函数第一个参数一定是隐藏的this，所以d1必须放在<<左侧
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
//	//声明日期类为时间类的友元类，则在日期类中可以直接访问Time类
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
//	class B //B天生就是A的友元
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
	A aa1;//有名对象，生命周期是当前作用域

	//不能这样定义对象，因为无法区分是函数声明还是对象定义
	//A aa1();

	//但是我们可以这样定义匿名对象，匿名对象的特点就是不用取名字
	//但是他的生命周期就只有这一行，我们可以看到下一行他就会自动调用析构函数
	A();

	A aa2(2);

	//匿名对象在这样的场景下就很好用
	Solution().Sum_solution(10);

	return 0;
}