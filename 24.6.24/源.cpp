#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Compute
{
public:
    static T getMax(T a, T b)
    {
        return max(a, b);
    }

    static T getMax(T a, T b, T c)
    {
        return max(a, max(b, c));
    }
};

int main() {
    int a, b, c;
    double x, y, z;
    cin >> a >> b >> c;
    cout << Compute<int>::getMax(a, b) << " " << Compute<int>::getMax(a, b, c) << endl;
    cin >> x >> y >> z;
    cout << Compute<double>::getMax(x, y) << " " << Compute<double>::getMax(x, y, z) << endl;
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Compute
{
public:
    static T getMax(T a, T b)
    {
        return max(a, b);
    }

    static T getMax(T a, T b, T c)
    {
        return max(a, max(b, c));
    }
};

int main() {
    int a, b, c;
    double x, y, z;
    cin >> a >> b >> c;
    cout << Compute<int>::getMax(a, b) << " " << Compute<int>::getMax(a, b, c) << endl;
    cin >> x >> y >> z;
    cout << Compute<double>::getMax(x, y) << " " << Compute<double>::getMax(x, y, z) << endl;
    return 0;
}

class Person

{

    static int n;

protected:

    string name_;

public:

    Person() { n++; cout << "A person without name is created." << endl; }

    Person(string name) :name_(name) { n++; cout << "Person " << name_ << " is created." << endl; }

    virtual ~Person() {
        n--;

        if (n != 0)cout << "Person " << name_ << " is erased." << endl;

        if (n == 0)cout << "A person without name is erased." << endl;

    }

};

int Person::n = 0;

class Teacher :virtual public Person

{

protected:

    string pos_;

public:

    Teacher(string name, string pos) :Person(name), pos_(pos) { cout << "Teacher " << name_ << " " << pos_ << " is created." << endl; }

    ~Teacher() { cout << "Teacher " << name_ << " is erased." << endl; }

};

class Student :virtual public Person

{

protected:

    double sco_;

public:

    Student(string name, double sco) :Person(name), sco_(sco) { cout << "Student " << name_ << " " << sco_ << " is created." << endl; }

    ~Student() { cout << "Student " << name_ << " is erased." << endl; }

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
    delete q;
    return 0;
}

