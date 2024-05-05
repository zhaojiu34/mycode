#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//
//		if (this != &aa)
//		{
//			_a == aa._a;
//		}
//
//		return (*this);
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//void f1(const A& aa)
//{}
//
//A& f2()
//{
//	A aa;
//	return aa;
//}
//
//
//int main()
//{
//	//传值传参
//	A aa1;
//	f1(aa1);
//	cout << endl;
//
//	//传值返回
//	f2();
//	cout << endl;
//
//	//隐式类型，连续构造+拷贝构造 -> 优化为直接构造
//	f1(1);
//
//	//一个表达式中，连续构造+构造拷贝 -> 优化为一个构造
//	f1(A(2));//匿名对象：具有常性
//	//一般不传匿名对象，直接传f1(2)
//	cout << endl;
//
//	//一个表达式中，连续拷贝构造+拷贝构造 -> 优化为一个拷贝构造
//	A aa2 = f2();
//	cout << endl;
//
//	//一个表达式中，连续构造+赋值重载 -> 无法优化
//	aa1 = f2();
//	cout << endl;
//
//
//	return 0;
//}

//class A
//{
//public:
//
//	A(int a =0)
//		:_a(a)
//	{}
//
//	~A()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	int _a;
//};
//
//void f2()
//{
//	//局部静态变量，只构造一次，生命周期是全局的，构造是第一次调用构造，之后不再调用构造
//	static A aa3 = 3;
//}
//
////全局变量
//A aa0 = 0;
//
//int main()
//{
//	//先定义的，后析构
//	A aa1 = 1;
//
//	A aa2 = 2;
//
//	f2();
//
//	return 0;
//}

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	int* p2 = (int*)calloc(4,sizeof(int));//开辟空间的同时，会把值初始化为0
//	int* p3 = (int*)realloc(p2, sizeof(int));
//
//	//这里不需要free(p2)
//	//如果后面的空间不够，realloc会把原本空间的值拷贝到另一块空间并把会把原本的空间free
//	//如果后面的空间足够，会在后面接着p2,free(p3)时就会把p2释放
//
//	free(p3);
//}

//void Test()
//{
//	//动态申请一个int类型的空间
//	//这样看和malloc在用法上没什么区别，只是更方便了
//	int* ptr4 = new int;
//
//	//动态申请一个int类型的空间并初始化为10
//	//与malloc有区别，可以初始化
//	int* ptr5 = new int(10);
//
//	//动态申请10个int型的空间
//	int* ptr6 = new int[10];
//
//	//也可以初始化多个对象
//	int* ptr7 = new int[10]{ 1,2,3,4 };//为说明的部分，默认初始化为0
//	
//	delete ptr4;
//	delete ptr5;
//
//	delete[] ptr6;
//	delete[] ptr7;
//
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//
//	A(int a1, int a2)
//	{
//		cout << "A(int a1 = 0, int a2 = 0)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	//不用隐式构造，需要先创建对象，再对象给数组传参
//	A aa1(1);
//	A aa2(2);
//	A aa3(3);
//	A aa4(4);
//	
//	A* p1 = new A[10]{ aa1,aa2,aa3,aa4};//构造+拷贝构造
//
//	//用隐式构造
//	//传两个参数时，可以再用一层{}
//	A* p2 = new A[10]{ 1,2,3,4,{5,6},7 };
//
//	delete[] p1;
//	delete[] p2;
//
//	return 0;
//}

//int main()
//{
//	//new/delete 和 malloc/free 最大的区别就是 new/delete 可以对于【自定义类型】
//	//除了开辟空间还会调用构造函数和析构函数
//	// malloc也可以为自定义类型开辟空间，但是开辟空间的同时无法做到初始化
//	// 因为自定义的成员是私有的，如果开辟空间的时候不初始化，之后就没办法再初始化
//	//new在为开辟空间时，如果没有传参，会默认调用自定义类型的默认构造
//
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	
//
//	//内置类型几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];//调用10次拷贝构造
//
//	free(p1);
//	delete p2;
//
//	free(p3);
//	delete p4;
//
//	free(p5);
//	delete[] p6;//调用10次析构函数
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
////定位new/replacement new
//int main()
//{
//
//	//p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;//注意：如果A类的构造函数有参数时，此时要传参
//	p1->~A();
//	free(p1);
//
//	//new/delete 原理
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//
//	p2->~A();
//	operator delete(p2);
//
//
//	//new[]/delete[] 的原理
//	A* p3 = (A*)operator new[](sizeof(A) * 10);
//	
//	//初始化
//	//new(p3) A[10] {1,2,3,4};
//	for (int i = 0; i < 10; i++)
//	{
//		new(p3 + i)A(10);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		(p3 + i) ->~A();
//	}
//	operator delete[](p2);
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};

int main()
{

	A* p1 = new A[10];//在底层开的空间是44，多开的4个是为了存数组的个数，这个个数无论多大，四个字节一定可以存下来
	int* p2 = new int[10];//底层的空间是40


	free(p1);//但是内置类型，如果有显示析构，混用会崩溃
	//delete[] p1;

	free(p2);//对于内置类型，new/malloc delete/free 混用是不会有太大问题

	return 0;
}