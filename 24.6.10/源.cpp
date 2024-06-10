#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <deque>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Point {
public:
    Point() {}
    Point(double x, double y) : x_(x), y_(y) {}
    void showPoint() { cout << "2D Point (" << x_ << "," << y_ << ")" << endl; }
protected:
    double x_;
    double y_;
};
class Point_3D :public Point {
public:
    Point_3D() {}
    Point_3D(double x, double y, double z) : Point(x, y), z_(z) {}
    void showPoint() { cout << "3D Point (" << x_ << "," << y_ << "," << z_ << ")" << endl; }
private:
    double z_;
};



class Point
{
private:
    double xx, yy;
    static int sumPoint;
public:
    Point(double _x = 0, double _y = 0) :xx(_x), yy(_y) { sumPoint++; }
    ~Point() {}
    void showPoint()
    {
        cout << "2D Point (" << xx << "," << yy << ")" << endl;
    }
    double x() { return xx; }
    double y() { return yy; }
    double x(int _x) { xx = _x; return xx; }
    double y(int _y) { yy = _y; return yy; }
    static int showNumber() { return sumPoint; }
};
int Point::sumPoint = 0;
class Point_3D :public Point
{
private:
    double zz;
    static int sumPoint_3D;
public:
    Point_3D(double _x = 0, double _y = 0, double _z = 0) :Point(_x, _y), zz(_z) { sumPoint_3D++; }
    ~Point_3D() {}
    void showPoint()
    {
        cout << "3D Point (" << x() << "," << y() << "," << zz << ")" << endl;
    }
    double z() { return zz; }
    void setPoint(double _x, double _y, double _z)
    {
        x(_x); y(_y); zz = _z;
    }
    static int showNumber() { return sumPoint_3D; }
};
int Point_3D::sumPoint_3D = 0;



class Square
{
public:
    Square(int le)
    {
        lenth = le;
        cout << "Construct Square (" << lenth << ")" << endl;
    }
    int length()
    {
        return lenth;
    }
    int perimeter()
    {
        return 4 * lenth;
    }
    int area()
    {
        return lenth * lenth;
    }
protected:
    int lenth;
};
class Rectangle :public Square
{
public:
    Rectangle(int le, int w) :Square(le)
    {
        wid = w;
        cout << "Construct Rectangle (" << lenth << ", " << wid << ")" << endl;
    }
    int length()
    {
        return lenth;
    }
    int width()
    {
        return wid;
    }
    int perimeter()
    {
        return 2 * (lenth + wid);
    }
    int area()
    {
        return lenth * wid;
    }
protected:
    int wid;
};
class Cuboid :public Rectangle
{
public:
    Cuboid(int l, int w, int h) :Rectangle(l, w)
    {
        high = h;
        cout << "Construct Cuboid (" << l << ", " << w << ", " << h << ")" << endl;
    }
    int length()
    {
        return lenth;
    }
    int width()
    {
        return wid;
    }
    int height()
    {
        return high;
    }
    int perimeter()
    {
        return 4 * (lenth + wid + high);
    }
    int area()
    {
        return lenth * wid * 2 + lenth * high * 2 + wid * high * 2;
    }
    int volume()
    {
        return lenth * wid * high;
    }
private:
    int high;
};




class Student {
private:
    string name_;
    bool sex_;
    int grade_;
    Student* next_;

public:
    Student(string n, bool s, int g)
        : name_(n)
        , sex_(s)
        , grade_(g)
        , next_(NULL)
    {
        cout << "A student named by " << name_ << " is created!" << endl;
    }
    ~Student()
    {
        cout << "A student named by " << name_ << " is erased." << endl;
    }
    void showInfo()
    {
        cout << "name = " << name_ << ", sex = " << sex_ << ", grade = " << grade_ << ";";
    }
    Student* getNext()
    {
        return next_;
    }
    void setNext(Student* n)
    {
        next_ = n;
    }
};

class StudentCadre : public Student {
private:
    string position_;

public:
    StudentCadre(string n, bool s, int g, string p)
        : Student(n, s, g)
        , position_(p)
    {
        cout << "A student cadre with position " << p << " is created." << endl;
    }
    ~StudentCadre() {}
    void showInfo()
    {
        Student::showInfo();
        cout << " position = " << position_ << ".";
    }
};