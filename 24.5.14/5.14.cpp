#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

////���͵Ľ���
//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
////�����͵Ľ���
//void Swap(float& left, float& right)
//{
//	float tmp = left;
//	left = right;
//	right = tmp;
//}
//
////�ַ��͵Ľ���
//void Swap(char& left, char& right)
//{
//	char tmp = left;
//	left = right;
//	right = tmp;
//}


////���ͱ��
////ʹ��ǰ�᣺�ڲ��߼�һ����ֻ�����Ͳ�ͬ
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}

//template<class T>//��tmplate <typename T>�ֽ׶ο�����Ϊ�ȼ�
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
//	//����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ�������������
//	// ͨ������a1��T����Ϊint������ͨ��ʵ��d2��T����Ϊdouble������ģ������б���ֻ��һ��T
//	// �������޷�ȷ���˴������ǽ�Tȷ��Ϊint����double������
//	// ע�⣺ģ���У��������ǲ���������������ת�������ģ���Ϊһ������ת�����⣬�������ᱳ�ڹ�
//	//Add(a1, d2);
//
//	//�˴������ֽ������
//	//1.�Լ�ǿ������ת��  2.ʹ����ʾ����ת��
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
//	//�˴������ֽ������
//	//1.�Լ�ǿ������ת��  2.ʹ����ʾ����ת��
//	//��ʵ����һ�ַ�����������дģ��ʱ��һ��ʼ������������
//	//��ô�����Ľ����ʲô���ͣ���ȡ�������Ǵ��εģ���δ֪�ģ���ʱ����auto�Զ������ͣ��ͺ���Ч��
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
//	Add(1, 2);//���ģ�溯��ƥ�䣬����Ҫģ�������ɣ��г�Ʒ���ó�Ʒ��
//	
//	Add(1, 20.0);//ģ�溯���������ɸ�ƥ��İ汾�������������ʵ�����ɸ�ƥ���Add����
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
	//A* ret = func(1);//����ͨ������ֵ������

	//�����������ʹ����ʽʵ����
	int* ret1 = func<int>(1);

	A* ret2 = func<A>(1);

	return 0;
}