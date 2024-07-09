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
//	//学号
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
//	//1.子类对象可以赋值给父类对象：切片
//	//不属于类型转换，不会产生临时变量
//	Person p = stu;
//	Person* pp = &stu;
//	Person& rp = stu;
//
//	//2.基类对象不可以赋值给派生类对象
//	Person person;
//	//stu = person;//error
//
//	//3基类对象可以通过强转赋值给派生类对象
//	pp = &stu;//原本是派生对象赋值过去的
//	Student* ps1 = (Student*)pp;//这种强制类型转换可以
//	ps1->_No = 10;
//	cout << ps1->_No << endl;
//
//	pp = &p;//父类对象本身
//	Student* ps2 = (Student*)pp;//这种就存在越界问题
//	ps2->_No = 20;
//	cout << ps2->_No << endl;
//
//		
//	return 0;
//}


////派生类和基类之间最好不要定义重名变量和函数，负责父类的会被子类隐藏
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
//		cout << "num2:" <<Person:: _num << endl;//如果父类中有重名的，要指定类域才可以使用父类的
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
//	//构造函数
//	Person(const char* name = "lisi")
//		:_name(name)
//	{
//		cout << "Person()默认构造函数" << endl;
//	}
//
//	//拷贝构造函数
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)拷贝构造" << endl;
//
//	}
//
//	//赋值
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)赋值" << endl;
//
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//
//	}
//
//	//析构函数
//	~Person()
//	{
//		cout << "~Person()析构函数" << endl;
//	}
//
//
//protected:
//	string _name;//姓名
//};
//
//class Student : public Person
//{
//public:
//	//构造函数
//	Student(const char* name = "zhangsan", int num = 999)
//		//相当于匿名对象
//		:Person(name)//调用父类的构造函数，初始化继承的父类那部分。如果父类没有默认构造函数，在初始化列表部分就必须初始化父类
//		,_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	//拷贝构造函数
//	Student(const Student& stu)
//		:Person(stu)//派生类可以赋值给基类变量
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
//			//父类中的operator=与派生类重名，要给基类赋值，要指定类域
//			Person::operator=(stu);
//			_num = stu._num;
//		}
//
//		cout << "Student& operator=(const Student& stu)" << endl;
//		
//		return *this;
//	}
//
//	//析构函数
//	~Student()
//	{
//		//父类的自动调用
//		cout << "~Student()" << endl;
//	}
//
//
//protected:
//	int _num;//学号
//};
//
////构造时是先父类再派生类
////析构时是先派生类再父类
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

//Problem A: 求最大值
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

////Problem B : 模拟用户登录
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

//Problem C: 简单教务系统中的用户

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
	delete q;//此处用delete删除，如果不用多态只会走~Person,不会Student和Person的析构
	return 0;
}