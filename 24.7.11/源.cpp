#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <iomanip>

using namespace std;

//class Point
//{
//private:
//    double a, b;
//public:
//    Point(double x = 0, double y = 0) { a = x, b = y; }
//    void show()
//    {
//        cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << endl;
//    }
//};
//
//int main()
//{
//    char c;
//    double a, b;
//    Point q;
//    while (std::cin >> a >> c >> b)
//    {
//        Point p(a, b);
//        p.show();
//    }
//    q.show();
//}


//class  Point
//{
//public:
//    Point()
//    {
//        _x = 0;
//        _y = 0;
//        cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is created." << endl;
//    }
//
//    Point(const Point& p)
//    {
//        _x = p._x;
//        _y = p._y;
//        cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is copied." << endl;
//    }
//
//    Point(double x, double y = 1)
//    {
//        _x = x;
//        _y = y;
//        cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is created." << endl;
//    }
//
//    void show()
//    {
//        std::cout << setprecision(16) << "Point : (" << _x << ", " << _y << ")" << endl;
//    }
//
//    ~Point()
//    {
//        cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is erased." << endl;
//    }
//
//private:
//    double _x;
//    double _y;
//};
//
//int main()
//{
//    char c;
//    double a, b;
//    Point q;
//    while (std::cin >> a >> c >> b)
//    {
//        Point p(a, b);
//        p.show();
//    }
//    Point q1(q), q2(1);
//    q1.show();
//    q2.show();
//    q.show();
//}


//class Point
//{
//private:
//    double a, b;
//public:
//    Point(double x = 0, double y = 0) {
//        a = x, b = y;
//        cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << " is created." << endl;
//    }
//    Point(int x)
//    {
//        a = x;
//        b = 1;
//        cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << " is created." << endl;
//    }
//    Point(Point& p)
//    {
//        a = p.a;
//        b = p.b;
//        cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << " is copied." << endl;
//    }
//    void show()
//    {
//        cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << endl;
//    }
//    ~Point()
//    {
//        cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << " is erased." << endl;
//    }
//};
//
//void showPoint(Point& p)
//{
//    Point q(p);
//    q.show();
//}
//
//void showPoint(Point& p1, Point& p2, Point& p3)
//{
//    Point q1(p1);
//    Point q2(p2);
//    Point q3(p3);
//    q1.show();
//    q2.show();
//    q3.show();
//}
//
//
//int main()
//{
//    char c;
//    double a, b;
//    Point q;
//    while (std::cin >> a >> c >> b)
//    {
//        Point p(a, b);
//        showPoint(p);
//    }
//    Point q1(q), q2(1);
//    showPoint(q1, q2, q);
//}

//static int num = 0;
//static int sum = 0;
//
//class Point
//{
//private:
//    double a, b;
//
//public:
//
//    Point(double x = 0, double y = 0) {
//        a = x, b = y;
//        sum++;
//        num++;
//    }
//    Point(int x)
//    {
//        sum++;
//        num++;
//        a = x;
//        b = 1;
//    }
//    Point(Point& p)
//    {
//        sum++;
//        num++;
//        a = p.a;
//        b = p.b;
//    }
//    void show()
//    {
//        cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << endl;
//    }
//    static void showCounter()
//    {
//        cout << "Current : " << num << " points." << endl;
//    }
//    static void showSumOfPoint()
//    {
//        cout << "In total : " << sum << " points." << endl;
//    }
//    ~Point()
//    {
//        num--;
//    }
//};
//
//void showPoint(Point& p)
//{
//    Point q(p);
//    q.show();
//}
//
//void showPoint(Point& p1, Point& p2, Point& p3)
//{
//
//    p1.show();
//    p2.show();
//    p3.show();
//}
//int main()
//{
//    char c;
//    double a, b;
//    Point q;
//    while (std::cin >> a >> c >> b)
//    {
//        Point p(a, b);
//        p.show();
//        p.showCounter();
//    }
//    q.showSumOfPoint();
//    Point q1(q), q2(1);
//    Point::showCounter();
//    showPoint(q1, q2, q);
//    Point::showSumOfPoint();
//}


int sum;

class Point {
public:
    Point(double a, double b) {
        x_ = a;
        y_ = b;
        sum++;
        pvl = sum;
    }
    Point() {
        x_ = y_ = 0;
        sum++;
        pvl = sum;
    }
    Point(double a) {
        x_ = y_ = a;
        sum++;
        pvl = sum;
    }
    Point(const Point& a) {
        x_ = a.x_;
        y_ = a.y_;
        sum++;
        pvl = sum;
    }
    double x() const { return x_; }
    double y() const { return y_; }
    double x(double x) {
        x_ = x;
        return x_;
    }
    double y(double y) {
        y_ = y;
        return y_;
    }
    void show() const {
        cout << setprecision(16);
        cout << "Point[" << pvl << "] : (" << x_ << ", " << y_ << ")" << endl;
    }
    Point& setPoint(double x, double y) {
        x_ = x;
        y_ = y;
        return *this;
    }
    bool isEqual(const Point& a) const {
        if (a.x_ == x_ && a.y_ == y_)
            return true;
        return false;
    }
    Point& copy(const Point& a) {
        x_ = a.x_;
        y_ = a.y_;
        return *this;
    }
    Point& inverse() {
        double t;
        t = x_;
        x_ = y_;
        y_ = t;
        return *this;
    }
    Point& inverse(const Point& a) {
        x_ = a.y_;
        y_ = a.x_;
        return *this;
    }

    static void showSumOfPoint() {
        cout << "In total : " << sum << " points." << endl;
    }

private:
    double x_, y_;
    int pvl;
};

void ShowPoint(const Point& p)
{
    cout << std::setprecision(16) << "Point : (" << p.x() << ", " << p.y() << ")" << endl;
}

void ShowPoint(double x, double y)
{
    cout << std::setprecision(16) << "Point : (" << x << ", " << y << ")" << endl;
}
int main()
{
    int l(0);
    char c;
    double a, b;
    Point p, q, pt[60];
    while (std::cin >> a >> c >> b)
    {
        if (a == b)
            p.copy(pt[l].setPoint(a, b));
        if (a > b)
            p.copy(pt[l].setPoint(a, b).inverse());
        if (a < b)
            p.inverse(pt[l].setPoint(a, b));
        if (a < 0)
            q.copy(p).inverse();
        if (b < 0)
            q.inverse(p).copy(pt[l]);
        pt[l++].show();
        p.show();
    }
    q.show();
    cout << "==========gorgeous separator==========" << endl;
    double x(0), y(0);
    for (int i = 0; i < l; i++)
        x += pt[i].x(), y -= pt[i].y();
    pt[l].x(y), pt[l].y(x);
    q.copy(pt[l]).show();
    for (int i = 0; i <= l; i++)
        pt[i].show();
    cout << "==========gorgeous separator==========" << endl;
    const Point const_point(3, 3);
    const_point.show();
    for (int i = 0; i <= l; i++)
    {
        if (const_point.isEqual(pt[i]))
        {
            ShowPoint(const_point);
            ShowPoint(const_point.x(), const_point.y());
            ShowPoint(Point(const_point.x(), const_point.y()));
        }
    }
    const_point.showSumOfPoint();
}