#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <stdlib.h>

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//
//};
//
//class Date
//{
//
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day =  1;
//
//	Time _t;
//};

//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_top = 0;
//		_capacity = n;
//	}
//
//	~Stack()
//	{
//		if (_a)//如果多次调用，第二次调用时由于_a已经释放了，不会再析构
//		{
//			free(_a);//如果没有写析构函数，默认生成的析构函数不会对指针进行析构的
//			//会发生内存泄漏
//			_a = nullptr;
//			_top = 0;
//			_capacity = 0;
//		}
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st;
//
//	st.~Stack();//可以显示调用,这样调用一次后，出main函数还会调用一次，相当于调用两次
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <stdlib.h>
//
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
//	 Date(const Date& d)
//	//Date(const Date d) 
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(d1);
//
//	return 0;
//}

//class Time
//{
//public:
//    Time()
//    {
//        _hour = 1;
//        _minute = 1;
//        _second = 1;
//    }
//    Time(const Time& t)
//    {
//        _hour = t._hour;
//        _minute = t._minute;
//        _second = t._second;
//        cout << "Time::Time(const Time&)" << endl;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date
//{
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//int main()
//{
//    Date d1;
//
//    // 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//    // 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构
//   // 造函数
//        Date d2(d1);
//    return 0;
//}

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
typedef int DataType;

class Stack
{
public:
    Stack(size_t capacity = 10)
    {
        _array = (DataType*)malloc(capacity * sizeof(DataType));
        if (nullptr == _array)
        {
            perror("malloc申请空间失败");
            return;
        }
        _size = 0;
        _capacity = capacity;
    }
    void Push(const DataType& data)
    {
        // CheckCapacity();
        _array[_size] = data;
        _size++;
    }
    ~Stack()
    {
        if (_array)
        {
            free(_array);
            _array = nullptr;
            _capacity = 0;
            _size = 0;
        }
    }
private:
    DataType* _array;
    size_t _size;
    size_t _capacity;
};

int main()
{
    Stack s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    Stack s2(s1);
    return 0;
}