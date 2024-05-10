#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<ctype.h>
using namespace std;

//class  Thing
//{
//private:
//    string name;
//public:
//    Thing() { name = ""; cout << "A thing without name is created!" << endl; }
//    Thing(Thing& p)
//    {
//        name = p.name;
//        if (p.name == "")
//            cout << "A thing without name is copied!" << endl;
//        else
//        {
//            cout << "A thing named by " << p.name << " is copied!" << endl;
//        }
//    }
//    Thing(string as)
//    {
//        name = as;
//        cout << "A thing named by " << name << " is created!" << endl;
//
//    }
//    ~Thing()
//    {
//        if (name == "")
//            cout << "A thing without name is erased!" << endl;
//        else
//        {
//            cout << "A thing named by " << name << " is erased!" << endl;
//        }
//    }
//};
//int main()
//{
//    string name;
//    Thing Thing1, Thing2(Thing1);
//    cin >> name;
//    Thing Thing3(name);
//    Thing Thing4(Thing3);
//    return 0;
//}

//class Person
//{
//public:
//    Person(string name = "no name", int age = 0)
//    {
//        _age = age;
//        _name = name;
//
//        cout << "A person whose name is \"" << _name << "\" and age is " << _age << " is created!" << endl;
//    }
//
//    Person(const Person& person)
//    {
//        _name = person._name;
//        _age = person._age;
//        cout << "A person whose name is \"" << _name << "\" and age is " << _age << " is cloned!" << endl;
//    }
//
//    Person& setName(string name)
//    {
//        _name = name;
//
//        return *this;
//    }
//
//    Person& setAge(int age)
//    {
//        _age = age;
//
//        return *this;
//    }
//
//    void showPerson()
//    {
//        cout << "This person is \"" << _name << "\" whose age is " << _age << "." << endl;
//    }
//
//    ~Person()
//    {
//        cout << "A person whose name is \"" << _name << "\" and age is " << _age << " is erased!" << endl;
//    }
//
//private:
//    string _name;
//    int _age;
//};
//
//int main()
//{
//    int cases;
//    char str[80];
//    int age;
//
//    Person noname, Tom("Tom", 16), anotherTom(Tom);
//    cin >> cases;
//    for (int ca = 0; ca < cases; ca++)
//    {
//        cin >> str >> age;
//        Person newPerson(str, age);
//        newPerson.showPerson();
//    }
//    anotherTom.setName(str).setAge(18);
//    anotherTom.showPerson();
//    noname.showPerson();
//    return 0;
//}

//class Equation {
//    double a, b, c;
//    double x1, x2;
//public:
//    Equation(double d, double e, double f) :a(d), b(e), c(f) {};
//    void solve() {
//        x1 = (-b + sqrt(b * b - 4 * a * c)) / a / 2;
//        x2 = (-b - sqrt(b * b - 4 * a * c)) / a / 2;
//    }
//    void printRoot() {
//        cout << fixed << setprecision(2) << max(x1, x2) << " ";
//        cout << fixed << setprecision(2) << min(x1, x2) << endl;
//    }
//
//};
//int main()
//{
//    double a, b, c;
//    while (cin >> a >> b >> c)
//    {
//        Equation equ(a, b, c);
//        equ.solve();
//        equ.printRoot();
//    }
//    return 0;
//}

//class Data
//{
//public:
//	Data()
//	{
//		flag = -1;
//		cout << "A default object is created." << endl;
//	}
//	Data(int in)
//	{
//		int_in = in;
//		flag = 0;
//		cout << "An integer object " << int_in << " is created." << endl;
//	}
//	Data(double in)
//	{
//		double_in = in;
//		flag = 1;
//		cout << "A double object " << double_in << " is created." << endl;
//	}
//	~Data()
//	{
//		if (flag == -1)
//			cout << "The default object is erased." << endl;
//		if (flag == 0)
//			cout << "The integer object " << int_in << " is erased." << endl;
//		if (flag == 1)
//			cout << "The double object " << double_in << " is erased." << endl;
//	}
//private:
//	int int_in;
//	double double_in;
//	int flag;
//
//};
//int main()
//{
//	Data d1;
//	int i;
//	cin >> i;
//	Data d2(i);
//	double d;
//	cin >> d;
//	Data d3(d);
//	return 0;
//}

using namespace std;

class Computer
{
private:
    char* n;
    static int cnt;
public:
    Computer(char* nn)
    {
        n = new char[strlen(nn) + 1];
        strcpy(n, nn);
        cnt++;
    }
    ~Computer()
    {
        delete[]n;
        cnt--;
    }
    Computer(const Computer& p)
    {
        n = new char[strlen(p.n) + 1];
        strcpy(n, p.n);
        cnt++;
    }
    Computer& setName(char* nn)
    {
        n = new char[strlen(nn) + 1];
        strcpy(n, nn);
        return *this;
    }
    void print()
    {
        cout << n << endl;
    }
    static int getCnt()
    {
        return cnt;
    }
};
int Computer::cnt = 0;
int main()
{
    char str[101];
    cout << "1:" << Computer::getCnt() << " computers." << endl;
    Computer com1("Tom"), com2(com1);
    cout << "2:" << com2.getCnt() << " computer." << endl;
    cin >> str;
    com2.setName(str).print();
    com2.print();
    cout << "3:" << com2.getCnt() << " computer." << endl;
    return 0;
}
