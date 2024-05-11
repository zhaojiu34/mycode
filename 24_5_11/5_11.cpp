#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class CharGraph
{
private:
    int f;
    char ch;
public:
    CharGraph(int a, char b) :f(a), ch(b) {}
    void print()
    {
        if (f == 0) cout << endl;
        else if (f > 0)
        {
            for (int i = 1; i <= f; i++)
            {
                for (int j = 0; j < i; j++)
                    cout << ch;
                cout << endl;
            }
        }
        else
        {
            for (int i = 1; i <= -1 * f; i++)
            {
                for (int j = 0; j < (-1 * f - i + 1); j++)
                    cout << ch;

                cout << endl;
            }
        }
    }
};
int main()
{
    int cases, n;
    char c;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> n >> c;
        CharGraph cGraph(n, c);
        cGraph.print();
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ret = 0;

class Student
{
public:
    Student(char* name, int* scores, int numOffcores)
    {
        _name = name;
        _scores = scores;
        _numOffcores = numOffcores;

        ret++;
        _id = ret;
        cout << "A student whose name is \"" << _name << "\" and id is " << _id << " is created!" << endl;
    }

    ~Student()
    {
        cout << "A student whose name is \"" << _name << "\" and id is " << _id << " is erased!" << endl;
    }

    void showStudent()
    {
        cout << "This student is \"" << _name << "\" whose id is " << _id << "." << endl;
        cout << "This student's scores are:";
        for (int i = 0; i < _numOffcores; i++)
            cout << " " << _scores[i];
        cout << endl;
    }
private:
    char* _name;
    int _numOffcores;
    int* _scores;
    int _id;
};
int main()
{
    int cases;
    char* str;
    int maxLenOfString, numOfCourses;
    int* scores;

    cin >> cases >> maxLenOfString >> numOfCourses;
    str = new char[maxLenOfString + 1];
    scores = new int[numOfCourses];
    for (int i = 0; i < cases; i++)
    {
        cin >> str;
        for (int j = 0; j < numOfCourses; j++)
            cin >> scores[j];
        Student stu(str, scores, numOfCourses);
        stu.showStudent();
    }
    return 0;
}

#include <cmath>
#include <iostream>
using namespace std;

class Point {
private:
    double x_, y_;

public:
    Point(int x, int y)
        : x_(x)
        , y_(y)
    {
    }
    Point(const Point& p)
        : x_(p.x_)
        , y_(p.y_)
    {
    }
    double x() const
    {
        return x_;
    }
    double y() const
    {
        return y_;
    }
};

class Circle {
private:
    Point c_;
    double r_;
    double ptpd(const Point& p)
    {
        return sqrt(pow(c_.x() - p.x(), 2) + pow(c_.y() - p.y(), 2));
    }

public:
    Circle(Point p, double r)
        : c_(p)
        , r_(r)
    {
    }
    Circle(const Circle& c)
        : c_(c.c_)
        , r_(c.r_)
    {
    }
    int JudgeRelation(const Circle& c)
    {
        double d = ptpd(c.c_);
        if (d > r_ + c.r_)
            return 1;
        else if (d < r_ + c.r_) {
            double rs = min(r_, c.r_);
            double rb = max(r_, c.r_);
            if (rs + d == rb)
                return 4;
            else if (rs + d < rb)
                return 2;
            else
                return 5;
        }
        else
            return 3;
    }
};

int main()
{
    int cases;
    double x, y, r;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> x >> y >> r;
        Point p1(x, y);
        Circle c1(p1, r);
        cin >> x >> y >> r;
        Point p2(x, y);
        Circle c2(p2, r);
        switch (c1.JudgeRelation(c2))
        {
        case 1:
            cout << "Outside" << endl;
            break;
        case 2:
            cout << "Inside" << endl;
            break;
        case 3:
            cout << "Externally tangent" << endl;
            break;
        case 4:
            cout << "Internally tangent" << endl;
            break;
        case 5:
            cout << "Intersection" << endl;
        }
    }
}

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
class Point
{
private:
    double x, y;
public:
    Point(double _x = 0, double _y = 0) :x(_x), y(_y)
    {
        cout << fixed << setprecision(2) << "The Point (" << x << ", " << y << ") is created!" << endl;
    }
    Point(const Point& p)
    {
        x = p.x;
        y = p.y;
        cout << fixed << setprecision(2) << "A Point (" << x << ", " << y << ") is copied!" << endl;
    }
    ~Point() { cout << fixed << setprecision(2) << "A Point (" << x << ", " << y << ") is erased!" << endl; }
    double getX() { return x; }
    double getY() { return y; }
};
class Graph
{
private:
    Point* point;
    int numOfPoints;
public:
    Graph()
    {
        point = NULL;
        numOfPoints = 0;
        cout << "A graph with " << numOfPoints << " points is created!" << endl;
    }
    Graph(Point* p, int num)
    {
        numOfPoints = num;
        point = new Point[numOfPoints];
        for (int i = 0; i < num; i++)
        {
            point[i] = p[i];
        }
        cout << "A graph with " << numOfPoints << " points is created!" << endl;
    }
    ~Graph() { delete[]point; cout << "A graph with " << numOfPoints << " points is erased!" << endl; }
    Point getCentroid()
    {
        Point* a;
        int i, j;
        double _x = 0, _y = 0, x, y;
        for (i = 0; i < numOfPoints; i++)
        {
            _x += (*(point + i)).getX();
            _y += (*(point + i)).getY();
        }
        x = _x / numOfPoints;
        y = _y / numOfPoints;
        a = new Point(x, y);
        return *a;
    }
};
int main()
{
    int cases, num;
    double x, y;
    Point centroid;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> num;
        Point points[num];
        for (int j = 0; j < num; j++)
        {
            cin >> x >> y;
            points[j] = *(new Point(x, y));
        }
        Graph graph(points, num);
        centroid = graph.getCentroid();
        cout << setprecision(2) << fixed << "The centroid is (" << centroid.getX() << ", " << centroid.getY() << ")." << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
class Character
{
public:
    friend istream& operator>>(istream& is, Character& c);
    char a;
    char operator+(const int& n)const
    {
        return (a + n % 26 - 'a' + 26) % 26 + 'a';
    }
    char operator-(const int& n)const
    {
        return (a - n % 26 - 'a' + 26) % 26 + 'a';
    }
};
istream& operator>>(istream& is, Character& c)
{
    char tmp;
    is >> tmp;
    c.a = tmp;
    return is;
}
int main()
{
    int cases, data;
    Character ch;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> ch;
        cin >> data;
        cout << (ch + data) << " " << (ch - data) << endl;
    }
}