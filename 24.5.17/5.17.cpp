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
//	//��ֵ����
//	A aa1;
//	f1(aa1);
//	cout << endl;
//
//	//��ֵ����
//	f2();
//	cout << endl;
//
//	//��ʽ���ͣ���������+�������� -> �Ż�Ϊֱ�ӹ���
//	f1(1);
//
//	//һ�����ʽ�У���������+���쿽�� -> �Ż�Ϊһ������
//	f1(A(2));//�������󣺾��г���
//	//һ�㲻����������ֱ�Ӵ�f1(2)
//	cout << endl;
//
//	//һ�����ʽ�У�������������+�������� -> �Ż�Ϊһ����������
//	A aa2 = f2();
//	cout << endl;
//
//	//һ�����ʽ�У���������+��ֵ���� -> �޷��Ż�
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
//	//�ֲ���̬������ֻ����һ�Σ�����������ȫ�ֵģ������ǵ�һ�ε��ù��죬֮���ٵ��ù���
//	static A aa3 = 3;
//}
//
////ȫ�ֱ���
//A aa0 = 0;
//
//int main()
//{
//	//�ȶ���ģ�������
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
//	int* p2 = (int*)calloc(4,sizeof(int));//���ٿռ��ͬʱ�����ֵ��ʼ��Ϊ0
//	int* p3 = (int*)realloc(p2, sizeof(int));
//
//	//���ﲻ��Ҫfree(p2)
//	//�������Ŀռ䲻����realloc���ԭ���ռ��ֵ��������һ��ռ䲢�ѻ��ԭ���Ŀռ�free
//	//�������Ŀռ��㹻�����ں������p2,free(p3)ʱ�ͻ��p2�ͷ�
//
//	free(p3);
//}

//void Test()
//{
//	//��̬����һ��int���͵Ŀռ�
//	//��������malloc���÷���ûʲô����ֻ�Ǹ�������
//	int* ptr4 = new int;
//
//	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	//��malloc�����𣬿��Գ�ʼ��
//	int* ptr5 = new int(10);
//
//	//��̬����10��int�͵Ŀռ�
//	int* ptr6 = new int[10];
//
//	//Ҳ���Գ�ʼ���������
//	int* ptr7 = new int[10]{ 1,2,3,4 };//Ϊ˵���Ĳ��֣�Ĭ�ϳ�ʼ��Ϊ0
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
//	//������ʽ���죬��Ҫ�ȴ��������ٶ�������鴫��
//	A aa1(1);
//	A aa2(2);
//	A aa3(3);
//	A aa4(4);
//	
//	A* p1 = new A[10]{ aa1,aa2,aa3,aa4};//����+��������
//
//	//����ʽ����
//	//����������ʱ����������һ��{}
//	A* p2 = new A[10]{ 1,2,3,4,{5,6},7 };
//
//	delete[] p1;
//	delete[] p2;
//
//	return 0;
//}

//int main()
//{
//	//new/delete �� malloc/free ����������� new/delete ���Զ��ڡ��Զ������͡�
//	//���˿��ٿռ仹����ù��캯������������
//	// mallocҲ����Ϊ�Զ������Ϳ��ٿռ䣬���ǿ��ٿռ��ͬʱ�޷�������ʼ��
//	// ��Ϊ�Զ���ĳ�Ա��˽�еģ�������ٿռ��ʱ�򲻳�ʼ����֮���û�취�ٳ�ʼ��
//	//new��Ϊ���ٿռ�ʱ�����û�д��Σ���Ĭ�ϵ����Զ������͵�Ĭ�Ϲ���
//
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	
//
//	//�������ͼ�����һ����
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];//����10�ο�������
//
//	free(p1);
//	delete p2;
//
//	free(p3);
//	delete p4;
//
//	free(p5);
//	delete[] p6;//����10����������
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
////��λnew/replacement new
//int main()
//{
//
//	//p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;//ע�⣺���A��Ĺ��캯���в���ʱ����ʱҪ����
//	p1->~A();
//	free(p1);
//
//	//new/delete ԭ��
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//
//	p2->~A();
//	operator delete(p2);
//
//
//	//new[]/delete[] ��ԭ��
//	A* p3 = (A*)operator new[](sizeof(A) * 10);
//	
//	//��ʼ��
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

	A* p1 = new A[10];//�ڵײ㿪�Ŀռ���44���࿪��4����Ϊ�˴�����ĸ���������������۶���ĸ��ֽ�һ�����Դ�����
	int* p2 = new int[10];//�ײ�Ŀռ���40


	free(p1);//�����������ͣ��������ʾ���������û����
	//delete[] p1;

	free(p2);//�����������ͣ�new/malloc delete/free �����ǲ�����̫������

	return 0;
}