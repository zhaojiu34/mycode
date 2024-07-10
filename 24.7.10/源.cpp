#define _CRT_SECURE_NO_WARNINGS 1

#include <bits/stdc++.h>


using namespace std;

//静态成员变量只有一份
//class Person
//{
//public:
//	Person()
//	{
//		_count++;
//	}
//	static int _count;
//
//protected:
//	string _name;
//};
//
//int Person::_count = 0;
//
//class Student :public Person
//{
//public:
//
//protected:
//	int _sNo;
//};
//
//class Graduate :public Student
//{
//public:
//
//protected:
//	string _sbuject;
//};
//
//
//int main()
//{
//	Student stu1;
//	Student stu2;
//	Student stu3;
//	Student stu4;
//
//	Graduate g1;
//
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;
//
//	return 0;
//}

////菱形继承会造成数据冗杂和数据二义性
//class Person
//{
//public:
//
//	public:
//	string _name;
//};
//
//class Student:virtual public Person
//{
//	public:
//	int _Num;//学号
//};
//
//class Teacher : virtual public Person
//{
//	public:
//	int _id;
//};
//
////在这个类中，就会又两个名字
//class Assistant : public Student, public Teacher
//{
//	public:
//	string _subject;
//};
//
//int main()
//{
//	Assistant a;
//	a.Student::_name = "lisi";
//	a.Teacher::_name = "Mr.li";
//
//	//解决办法：使用虚继承：在第一次会出现数据冗杂的地方使用virtual
//	a._name = "zhangsan";
//
//	return 0;
//}


////虚函数
//class Person
//{
//public:
//	virtual void BuyTicket()//虚函数
//	{
//		cout << "买票-全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	void BuyTicket()//虚函数的重写
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//
////多态
////1.有父类的指针或者引用，并且调用虚函数
////2.别调用函数必须是虚函数，并且必须对派生类的虚函数进行重写
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person* p = new Person;
//	Person* p1 = new Student;
//	Func(*p);
//	Func(*p1);
//
//	return 0;
//}

//Problem C: 简单教务系统中的用户
//class Person
//{
//
//public:
//    Person(string _name = "")
//        :_name(_name)
//    {
//
//        if (_name == "")
//        {
//            cout << "A person without name is created." << endl;
//        }
//        else
//        {
//            cout << "Person " << _name << " is created." << endl;
//        }
//    }
//
//    virtual  ~Person()
//    {
//        if (_name == "")
//        {
//            cout << "A person without name is erased."<<endl;
//        }
//        else
//        {
//            cout << "Person " << _name << " is erased." << endl;
//        }
//   }
//
//protected:
//    string _name;
//};
//
//
//class Student :public Person
//{
//public:
//    Student(string name, double score)
//        :Person(name)
//        ,_score(score)
//    {
//        cout << "Student " << _name << " " << _score << " is created." << endl;
//    }
//
//    virtual ~Student()
//    {
//        cout << "Student " << _name << " is erased." << endl;
//    }
//
//protected:
//    double _score;
//};
//
//
//class Teacher : public Person
//{
//public:
//    Teacher(string name, string id)
//        :Person(name)
//        , _id(id)
//    {
//        cout << "Teacher " << _name << " " << _id << " is created." << endl;
//    }
//
//    virtual ~Teacher()
//    {
//        cout << "Teacher " << _name << " is erased." << endl;
//    }
//
//    
//protected:
//    string _id;
//};
//
//
//int main() 
//{
//    string name, pos;
//    double sco;
//    cin >> name >> pos >> sco;
//    Person person;
//    Person* p;
//    p = new Teacher(name, pos);
//    delete p;
//    Person* q;
//    q = new Student(name, sco);
//    delete q;
//    return 0;
//}

////没做出来
////Problem D: 向量的排序:vector二维数组
//class Point
//{
//public:
//	friend istream& operator>>(istream& is, Point& p);
//	Point(int n = 0)
//		:_n(n)
//	{
//		_v.resize(n, 0);
//	}
//
//	int n()
//	{
//		return _n;
//	}
//
//	vector<int> _v;
//
//private:
//	int _n;
//};
//
//istream& operator>>(istream& is, Point& p)
//{
//	for (size_t i = 0; i < p._n; i++)
//	{
//		is >> p._v[i];
//	}
//
//	return is;
//}
//
//class PointList
//{
//public:
//	friend ostream& operator<<(ostream& os, PointList& pl);
//
//	PointList operator+(Point& p)
//	{
//		_pl.push_back(p);
//		return *this;
//	}
//
//	static bool  CompareDistance(Point p1, Point p2)
//	{
//		double dist1 = 0.0, dist2 = 0.0;
//		for (int i = 0; i < p1.n(); i++)
//		{
//			dist1 += pow(p1._v[i], 2);
//		}
//		for (int i = 0; i < p2.n(); i++)
//		{
//			dist2 += pow(p2._v[i], 2);
//		}
//		if (dist1 < dist2)
//		{
//			return true;
//		}
//
//
//		return false;
//	}
//
//	void Sort()
//	{
//		sort(_pl.begin(), _pl.end(), CompareDistance);
//	}
//
//private:
//	vector<Point> _pl;
//};
//
//ostream& operator<<(ostream& os, PointList& pl)
//{
//	for (size_t i = 0; i < pl._pl.size(); i++)
//	{
//		os << "[";
//		for (size_t j = 0; j < pl._pl[i].n(); j++)
//		{
//			if (j != 0)
//				os << ",";
//
//			os << pl._pl[i]._v[j];
//		}
//		os << "]"<<endl;
//	}
//
//	return os;
//}
//
//
//int main() 
//{
//	PointList pl;
//	int m, n, i;
//	cin >> m >> n;
//	for (i = 0; i < m; i++) {
//		Point tmp(n);
//		cin >> tmp;
//		pl = pl + tmp;
//	}
//	pl.Sort();
//	cout << pl;
//	return 0;
//}

////Problem E: 导演、演员和电影
//class Person
//{
//public:
//	Person(string name = "")
//		:_name(name)
//	{
//		cout << "Person " << _name << " is created." << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person " << _name << " is erased." << endl;
//	}
//protected:
//	string _name;
//};
//
//class Director:public Person
//{
//public:
//	Director(string name = "")
//		:Person(name)
//	{
//		cout << "Director " << _name << " is created." << endl;
//	}
//
//	~Director()
//	{
//		cout << "Director " << _name << " is erased." << endl;
//
//	}
//
//
//};
//
//class Actor :public Person
//{
//public:
//	Actor(string name = "")
//		:Person(name)
//	{
//		cout << "Actor " << _name << " is created." << endl;
//	}
//
//
//	~Actor()
//	{
//		cout << "Actor " << _name << " is erased." << endl;
//
//	}
//
//};
//
//class Film
//{
//public:
//	Film(string _dor, string aor, string film)
//		:_film(film)
//		,_dor(_dor)
//		,_aor(aor)
//	{
//		
//		cout << "Film " << _film << " is created." << endl;
//	}
//
//	~Film()
//	{
//		cout << "Film " << _film << " is erased." << endl;
//	}
//
//private:
//	Director _dor;
//	Actor _aor;
//	string _film;
//};
//
//int main() {
//	string directorName, actorName, filmName;
//	cin >> directorName >> actorName >> filmName;
//	Person person(directorName);
//	Director director(directorName);
//	Actor actor(actorName);
//	Film film(directorName, actorName, filmName);
//	return 0;
//}


////Problem F: 猫、狗和公鸡的工作
//class Animal
//{
//public:
//    Animal()
//    {
//        cout << "An animal is created." << endl;
//    }
//
//    virtual ~Animal()
//    {
//        cout << "An animal is erased." << endl;
//    }
//
//    void work()
//    {
//
//    }
//
//protected:
//
//};
//
//class Dog:public Animal
//{
//public:
//    Dog()
//        :Animal()
//    {
//        cout << "A dog is created." << endl;
//    }
//
//    void work()
//    {
//        cout << "Dog can watch the house." << endl;
//    }
//
//    virtual ~Dog()
//    {
//        cout << "A dog is erased." << endl;
//    }
//protected:
//
//};
//
//class Cat :public Animal
//{
//public:
//    Cat()
//        :Animal()
//    {
//        cout << "A cat is created." << endl;
//    }
//
//    void work()
//    {
//        cout << "Cat can catch mouses." << endl;
//    }
//
//    virtual ~Cat()
//    {
//        cout << "A cat is erased." << endl;
//    }
//protected:
//
//};
//
//class Cock :public Animal
//{
//public:
//    Cock()
//        :Animal()
//    {
//        cout << "A cock is created." << endl;
//
//    }
//
//    void work()
//    {
//        cout << "Cat can catch mouses." << endl;
//    }
//
//    virtual ~Cock()
//    {
//        cout << "Cock can wake people up." << endl;
//    }
//protected:
//
//};
//
//int main()
//{
//    vector<Animal*> animals;
//    vector<Animal*>::iterator p;
//    string type;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> type;
//        if (type == "cat")
//            animals.push_back(new Cat());
//        else if (type == "dog")
//            animals.push_back(new Dog());
//        else if (type == "cock")
//            animals.push_back(new Cock());
//    }
//    for (p = animals.begin(); p != animals.end(); p++)
//    {
//
//        (*p)->work();
//    }
//    for (int i = 0; i < n; i++)
//        delete animals[i];
//    animals.clear();
//    return 0;
//}

////Problem G: Simple类
//class Simple
//{
//public:
//	Simple(int n = 0)
//		:_n(n)
//	{
//		cout << "Simple " << _n << " is created." << endl;
//	}
//
//	Simple(const Simple& s)
//		:_n(s._n)
//	{
//		cout << "Simple " << _n << " is copied." << endl;
//	}
//
//	~Simple()
//	{
//		cout << "Simple " << _n << " is erased." << endl;
//	}
//
//	Simple& setMem(int n)
//	{
//		_n = n;
//
//		return  *this;
//	}
//
//	int getMem()
//	{
//		return _n;
//	}
//	
//	void print()
//	{
//		cout << _n << endl;
//	}
//private:
//	int _n;
//};
//
//int main()
//{
//	int m;
//	cin >> m;
//	Simple s1, s2(m);
//	Simple s3;
//	s3.setMem(m).print();
//	s3.setMem(m + 1);
//	cout << s3.getMem() << endl;
//	Simple s4(s3);
//	s4.print();
//	return 0;
//}


////Problem J: 计算课程成绩
//class Mark
//{
//public:
//    void input()
//    {
//        cin >> _n;
//        _score.resize(_n, 0);
//        _d.resize(_n, 0.0);
//
//        for (size_t i = 0; i < _n; i++)
//        {
//            cin >> _score[i];
//        }
//
//        for (size_t i = 0; i < _n; i++)
//        {
//            cin >> _d[i];
//        }
//
//    }
//
//    double getFinalMark()
//    {
//        double sum = 0;
//        for (size_t i = 0; i < _n; i++)
//        {
//            sum += _score[i] * _d[i];
//        }
//        return sum;
//    }
//
//
//private:
//    int _n;
//    vector<int> _score;
//    vector<double> _d;
//};
//
//int main()
//{
//    Mark mark;
//    mark.input();
//    cout << mark.getFinalMark() << endl;
//    return 0;
//}


////Problem I : 数据补齐
//class Array
//{
//public:
//
//    void input()
//    {
//        cin >> _n;
//        _a.resize(_n, 0);
//        for (size_t i = 0; i < _n; i++)
//        {
//            cin >> _a[i];
//        }
//
//    }
//
//    void output()
//    {
//        for (size_t i = 0; i < _a.size(); i++)
//        {
//            if (i != 0)
//            {
//                cout << " ";
//            }
//            cout << _a[i];
//        }
//    }
//
//    void Complete()
//    {
//        for (size_t i = 0; i < _a.size(); i++)
//        {
//            if (_a[i] == -1)
//            {
//                _a[i] = (_a[i - 1] + _a[i + 1])/2;
//            }
//        }
//    }
//
//private:
//    int _n;
//    vector<int> _a;
//};
//
//
//int main()
//{
//    Array arr;
//    arr.input();
//    arr.Complete();
//    arr.output();
//    return 0;
//}


//Problem H: 回文素数

bool pdss(int n)
{
    //判断是不是素数
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;

    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;

}

//判断是不是回文数字
bool pdhw(int n)
{
    if (n >= 10 && n <= 99)
    {
        if (n / 10 == n % 10)return true;
    }
    if (n >= 100 && n <= 999)
    {
        if (n / 100 == n % 10)return true;
    }
    if (n >= 1000 && n <= 9999)
    {
        if ((n % 10 == n / 1000) && (n / 10 % 10 == n / 100 % 10))return true;
    }
    if (n >= 10000 && n <= 99999)
    {
        if ((n % 10 == n / 10000) && (n / 10 % 10 == n / 1000 % 10))return true;
    }

    return false;
}


int flag = 0;//用来打印空格

class Symm
{
private:
    int n;

public:
    Symm(int x) 
        :n(x) 
    {}

    void print()
    {
        if (n == 1)cout << "2 3 5 7";

        if (n == 2)
        {
            for (int i = 10; i <= 99; i++)
            {

                if (pdss(i) && pdhw(i))
                {
                    if (flag == 1)
                        cout << " ";

                    flag = 1;
                    cout << i;
                }

            }
        }

        if (n == 3)
        {
            for (int i = 100; i <= 999; i++)
            {

                if (pdss(i) && pdhw(i))
                {
                    if (flag == 1)
                       cout << " ";

                    flag = 1;
                    cout << i;
                }

            }
        }

        if (n == 4)
        {
            for (int i = 1000; i <= 9999; i++)
            {

                if (pdss(i) && pdhw(i))
                {
                    if (flag == 1)cout << " ";
                    flag = 1;
                    cout << i;
                }

            }
        }

        if (n == 5)
        {
            for (int i = 10000; i <= 99999; i++)
            {

                if (pdss(i) && pdhw(i))
                {
                    if (flag == 1)cout << " ";
                    flag = 1;
                    cout << i;
                }

            }
        }

    }

};

int main()
{
    int m;
    cin >> m;
    Symm symm(m);
    symm.print();
    return 0;
}
