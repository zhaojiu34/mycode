#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//
//protected:
//	int _age = 18;
//	string  _name = "zhangsan";
//};
//
//class Student : public Person
//{
//protected:
//	//ѧ��
//	int _stuid;
//};
//
//class Teacher : public Person
//{
//
//protected:
//	int _jobid;
//};

//int main()
//{
//	Student stu;
//	Teacher teacher;
//
//	stu.Print();
//	teacher.Print();
//
//	return 0;
//}


//class Person
//{
//protected:
//	int _age;
//	string _name;
//	string _sex;
//};
//
//class Student : public Person
//{
//public:
//	int _No;
//};
//
//int main()
//{
//	Student stu;
//
//	//1.���������Ը�ֵ�����������Ƭ
//	//����������ת�������������ʱ����
//	Person p = stu;
//	Person* pp = &stu;
//	Person& rp = stu;
//
//	//2.������󲻿��Ը�ֵ�����������
//	Person person;
//	//stu = person;//error
//
//	//3����������ͨ��ǿת��ֵ�����������
//	pp = &stu;//ԭ������������ֵ��ȥ��
//	Student* ps1 = (Student*)pp;//����ǿ������ת������
//	ps1->_No = 10;
//	cout << ps1->_No << endl;
//
//	pp = &p;//���������
//	Student* ps2 = (Student*)pp;//���־ʹ���Խ������
//	ps2->_No = 20;
//	cout << ps2->_No << endl;
//
//		
//	return 0;
//}


////������ͻ���֮����ò�Ҫ�������������ͺ�����������Ļᱻ��������
//class Person
//{
//protected:
//	string _name = "lisi";
//	int _num = 111;
//
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name<<endl;
//		cout << "num1:" << _num << endl;
//		cout << "num2:" <<Person:: _num << endl;//����������������ģ�Ҫָ������ſ���ʹ�ø����
//	}
//
//protected:
//	int _num = 999;
//
//};
//
//int main()
//{
//	Student stu;
//	stu.Print();
//
//	return 0;
//}


//class Person
//{
//public:
//
//	//���캯��
//	Person(const char* name = "lisi")
//		:_name(name)
//	{
//		cout << "Person()Ĭ�Ϲ��캯��" << endl;
//	}
//
//	//�������캯��
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)��������" << endl;
//
//	}
//
//	//��ֵ
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)��ֵ" << endl;
//
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//
//	}
//
//	//��������
//	~Person()
//	{
//		cout << "~Person()��������" << endl;
//	}
//
//
//protected:
//	string _name;//����
//};
//
//class Student : public Person
//{
//public:
//	//���캯��
//	Student(const char* name = "zhangsan", int num = 999)
//		//�൱����������
//		:Person(name)//���ø���Ĺ��캯������ʼ���̳еĸ����ǲ��֡��������û��Ĭ�Ϲ��캯�����ڳ�ʼ���б��־ͱ����ʼ������
//		,_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	//�������캯��
//	Student(const Student& stu)
//		:Person(stu)//��������Ը�ֵ���������
//		, _num(stu._num)
//	{
//		cout << "Student(const Student& stu)" << endl;
//	}
//
//	//operator=
//	Student& operator=(const Student& stu)
//	{
//		if (&stu != this)
//		{
//			//�����е�operator=��������������Ҫ�����ำֵ��Ҫָ������
//			Person::operator=(stu);
//			_num = stu._num;
//		}
//
//		cout << "Student& operator=(const Student& stu)" << endl;
//		
//		return *this;
//	}
//
//	//��������
//	~Student()
//	{
//		//������Զ�����
//		cout << "~Student()" << endl;
//	}
//
//
//protected:
//	int _num;//ѧ��
//};
//
////����ʱ���ȸ�����������
////����ʱ�����������ٸ���
//
//
//void Test()
//{
//	Student stu1("Jack", 18);
//	cout << endl;
//
//	Student stu2(stu1);
//	cout << endl;
//
//	Student stu3("Rose",16);
//	stu1 = stu3;
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}


#include <bits/stdc++.h>

//Problem A: �����ֵ
//template<class T>
//class Compute
//{
//public:
//	static T getMax(T a, T b, T c)
//	{
//		return max(a, max(b, c));
//	}
//
//	static T getMax(T a, T b)
//	{
//		return max(a, b);
//	}
//
//};
//
//
//int main() 
//{
//	int a, b, c;
//	double x, y, z;
//	cin >> a >> b >> c;
//	cout << Compute<int>::getMax(a, b) << " " << Compute<int>::getMax(a, b, c) << endl;
//	cin >> x >> y >> z;
//	cout << Compute<double>::getMax(x, y) << " " << Compute<double>::getMax(x, y, z) << endl;
//	return 0;
//}

////Problem B : ģ���û���¼
//class Accounts
//{
//public:
//
//	Accounts()
//	{
//		_my.resize(100, "");
//		_mi.resize(100, "");
//	}
//
//	void addUser(const string my, const string mi)
//	{
//		_my[i] = my;
//		_mi[i] = mi;
//
//		i++;
//	}
//
//	void login(const string my, const string mi)
//	{
//		for (size_t i = 0; i < _my.size(); i++)
//		{
//			if (_my[i] == my)
//			{
//				if (_mi[i] == mi)
//				{
//					cout << "welcome" << endl;
//					return;
//				}
//				else
//				{
//					cout << "password error" << endl;
//					return;
//				}
//			}
//		}
//		cout << "user name error" << endl;
//	}
//
//private:
//	vector<string> _my;
//	vector<string> _mi;
//	static int i;
//};
//
// int Accounts::i = 0;
//
// int main() 
// {
//	 int n, i;
//	 string a, b;
//	 Accounts accounts;
//	 cin >> n;
//	 for (i = 0; i < n; i++)
//	 {
//		 cin >> a >> b;
//		 accounts.addUser(a, b);
//	 }
//
//	 cin >> n;
//	 for (i = 0; i < n; i++)
//	 {
//		 cin >> a >> b;
//		 accounts.login(a, b);
//	 }
//	 return 0;
// }

//Problem C: �򵥽���ϵͳ�е��û�

class Person
{
	static int n;
public:

	Person()
	{
		cout << "A person without name is created" << endl;
		n++;
	}

	Person(string name)
		:_name(name)
	{
		n++;
		
		cout << "Person " << _name << " is created" << endl;
	}

	virtual ~Person()
	{
		n--;
		if (n==0)
		{
			cout << "A person without name is erased." << endl;
		}
		else
		{
			cout << "Person " << _name << " is erased" << endl;
		}

	}

protected:
	string _name;

};
int Person::n = 0;

class Teacher : virtual public Person
{
public:

	Teacher(string name = "",string teacher ="")
		:Person(name)
		,_teacher(teacher)
	{
		cout << "Teacher " << _name << " " << _teacher << " is created." << endl;
	}

	virtual ~Teacher()
	{
		cout << "Teacher " << _name << " is erased" << endl;

	}

protected:
	string _teacher;
};

class Student : virtual public Person
{
public:
	Student(string name = "", int score = 0)
		:Person(name)
		,_score(score)
	{
		cout << "Student " << _name << " " << _score<<" is created" << endl;
	}


	~Student()
	{
		cout << "Student " << _name << " is erased" << endl;
	}

protected:
	int _score;
};


int main() {
	string name, pos;
	double sco;
	cin >> name >> pos >> sco;
	Person person;
	Person* p;
	p = new Teacher(name, pos);
	delete p;
	Person* q;
	q = new Student(name, sco);
	delete q;//�˴���deleteɾ����������ö�ֻ̬����~Person,����Student��Person������
	return 0;
}