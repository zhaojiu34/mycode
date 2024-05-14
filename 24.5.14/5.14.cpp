#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

////整型的交换
//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
////浮点型的交换
//void Swap(float& left, float& right)
//{
//	float tmp = left;
//	left = right;
//	right = tmp;
//}
//
////字符型的交换
//void Swap(char& left, char& right)
//{
//	char tmp = left;
//	left = right;
//	right = tmp;
//}


////泛型编程
////使用前提：内部逻辑一样，只是类型不同
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}

//template<class T>//与tmplate <typename T>现阶段可以认为等价
//
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	
//	Add(a1, a2);
//	Add(d1, d2);
//
//
//	//该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其参数类型
//	// 通过参数a1将T推演为int，但是通过实参d2将T推演为double，但是模版参数列表中只有一个T
//	// 编译器无法确定此处到底是将T确定为int还是double而报错
//	// 注意：模版中，编译器是不会主动进行类型转换操作的，因为一旦出现转化问题，编译器会背黑锅
//	//Add(a1, d2);
//
//	//此处有两种解决方案
//	//1.自己强制类型转换  2.使用显示类型转换
//	Add(a1, (int)d1);
//
//
//	return 0;
//}


//template<class T1,class T2>
//
//auto Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.22, d2 = 20.0;
//	//Add(a1, d2);
//
//	//此处有两种解决方案
//	//1.自己强制类型转换  2.使用显示类型转换
//	//其实还有一种方法，就是在写模版时，一开始就用两种类型
//	//那么函数的结果是什么类型，是取决于我们传参的，是未知的，这时候用auto自动推类型，就很有效果
//	auto ret = Add(a1, d1);
//	cout << ret << endl;
//
//
//	return 0;
//}


//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//
//template <class T>
//T Add(T left, T right)
//{
//	cout << "T Add(T left, T right)" << endl;
//	return left + right;
//}
//
////template<class T1,class T2>
////
////auto Add(const T1& left, const T2& right)
////{
////	cout << "auto Add(const T1& left, const T2& right)" << endl;
////	return left + right;
////}
//
//int main()
//{
//	Add(1, 2);//与非模版函数匹配，不需要模版在生成（有成品就用成品）
//	
//	Add(1, 20.0);//模版函数可以生成更匹配的版本，编译器会根据实参生成更匹配的Add函数
//
//	return 0;
//}

class A
{
	int _a;
};

template <class T>
T* func(int a)
{
	T* p = (T*)operator new(sizeof(T));
	new(p)T(a);

	return p;
}

int main()
{
	//A* ret = func(1);//不能通过返回值类型推

	//这种情况必须使用显式实例化
	int* ret1 = func<int>(1);

	A* ret2 = func<A>(1);

	return 0;
}