#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
public:
    Person() {}
    Person(string _name) :name(_name)
    {
        cout << "Person " << name << " is created." << endl;
    }
    ~Person()
    {
        cout << "Person " << name << " is erased." << endl;
    }
};
class Student :public Person
{
private:
    int id;
public:
    Student(string _name, int _id) :Person(_name)
    {
        id = _id;
        //name = _name;
        cout << "Student " << name << " with id " << id << " is created." << endl;
    }
    ~Student()
    {
        cout << "Student " << name << " with id " << id << " is erased." << endl;
    }
};
class Teacher :public Person
{
private:
    string position;
public:
    Teacher(string _name, string _position) :Person(_name)
    {
        //name = _name;
        position = _position;
        cout << "Teacher " << name << " with position " << position << " is created." << endl;
    }
    ~Teacher()
    {
        cout << "Teacher " << name << " with position " << position << " is erased." << endl;
    }
};
class Course
{
private:
    Teacher teacher;
    Student student;
    string name;
public:
    Course(string s1, string s2, string _position, string _name, int _id) :student(s2, _id), teacher(s1, _position)
    {
        name = _name;
        cout << "Course " << name << " is created." << endl;
    }
    ~Course()
    {
        cout << "Course " << name << " is erased." << endl;
    }

};


#include <string>
using namespace std;

class Vehicle {
private:
    int num_;

public:
    Vehicle(int n)
        : num_(n)
    {
        cout << "Vehicle has " << num_ << " wheels is created." << endl;
    }
    virtual ~Vehicle()
    {
        cout << "Vehicle has " << num_ << " wheels is erased." << endl;
    }
};

class Bus : public Vehicle {
private:
    int guest_;

public:
    Bus(int w, int g)
        : Vehicle(w)
        , guest_(g)
    {
        cout << "Bus which can carry " << guest_ << " persons is created." << endl;
    }
    ~Bus()
    {
        cout << "Bus which can carry " << guest_ << " persons is erased." << endl;
    }
};

class Truck : public Vehicle {
private:
    int weight_;

public:
    Truck(int wl, int wg)
        : Vehicle(wl)
        , weight_(wg)
    {
        cout << "Truck which can carry " << weight_ << " tons goods is created." << endl;
    }
    ~Truck()
    {
        cout << "Truck which can carry " << weight_ << " tons goods is erased." << endl;
    }
};