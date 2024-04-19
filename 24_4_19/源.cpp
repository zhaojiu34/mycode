#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <iomanip>
using namespace std;


//void Swap(int* x, int* y)
//{
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//
//void  Swap(double* x, double* y)
//{
//    double tmp = *x;
//    *x = *y;
//    *y = tmp;
//
//}
//void Swap(int& x, int& y)
//{
//    int tmp = x;
//    x = y;
//    y = tmp;
//}
//
//void Swap(double& x, double& y)
//{
//    double tmp = x;
//    x = y;
//    y = tmp;
//}
//int main()
//{
//    int x1, y1;
//
//    cin >> x1 >> y1;
//    Swap(&x1, &y1);
//    cout << x1 << " " << y1 << endl;
//
//    cin >> x1 >> y1;
//    Swap(x1, y1);
//    cout << x1 << " " << y1 << endl;
//
//    double x2, y2;
//
//    cin >> x2 >> y2;
//    Swap(&x2, &y2);
//    cout << x2 << " " << y2 << endl;
//
//    cin >> x2 >> y2;
//    Swap(x2, y2);
//    cout << x2 << " " << y2 << endl;
//}


//int f(int x, int y, int z)
//{
//	return 2 * (x - y + z);
//}
//
//int f(int x, int y)
//{
//	return 2 * (x - y);
//}
//
//int f(int x)
//{
//	return 2 * (x - 1);
//}
//
//int main()
//{
//	int n, x, y, z;
//	while (cin >> n)
//	{
//		if (n == 3)
//		{
//			cin >> x >> y >> z;
//			cout << f(x, y, z) << endl;
//		}
//		if (n == 2)
//		{
//			cin >> x >> y;
//			cout << f(x, y) << endl;
//		}
//		if (n == 1)
//		{
//			cin >> x;
//			cout << f(x) << endl;
//		}
//		if (n == 0)
//			break;
//	}
//}


//double area(double r = 1.0)
//{
//	return 3.14 * r * r;
//}
//
//
//int main()
//{
//	double r;
//	cin >> r;
//	cout << area(r) << endl;
//	cout << area() << endl;
//	return 0;
//}

//int max(int a, int b)
//{
//	if (a > b)
//		return a;
//	else
//		return b;
//}
//
//double max(double a, double b)
//{
//	double c = a - b;
//
//	if (c > 0)
//		return a;
//	else
//		return b;
//}
//int main()
//{
//	int a, b;
//	double c, d;
//	cin >> a >> b;
//	cout << max(a, b) << endl;
//	cin >> c >> d;
//	cout << max(c, d) << endl;
//	return 0;
//}


//void get_num(int& a, int& b, int& c)
//{
//	cin >> a >> b >> c;
//
//}
//
//void max_min(int& mmax, int& mmin, int a, int b, int c)
//{
//	mmax = a;
//	mmin = a;
//
//	if (mmax < b)
//		mmax = b;
//
//	if (mmax < c)
//		mmax = c;
//
//	if (mmin > c)
//		mmin = c;
//
//	if (mmin > b)
//		mmin = b;
//
//}
//
//int main()
//{
//	int cases;
//	int mmax, mmin, a, b, c;
//
//	cin >> cases;
//	for (int i = 1; i <= cases; ++i)
//	{
//		get_num(a, b, c);
//		max_min(mmax, mmin, a, b, c);
//		cout << "case " << i << " : " << mmax << ", " << mmin << endl;
//	}
//}

//class Point
//{
//private:
//	double a, b;
//public:
//	Point(double x = 0, double y = 0) { a = x, b = y; }
//	void show()
//	{
//		cout << setprecision(16) << "Point : (" << a << ", " << b << ")" << endl;
//	}
//};
//
//int main()
//{
//	char c;
//	double a, b;
//	Point q;
//	while (std::cin >> a >> c >> b)
//	{
//		Point p(a, b);
//		p.show();
//	}
//	q.show();
//}

class  Point
{
public:
	Point()
	{
		_x = 0;
		_y = 0;
		cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is created." << endl;
	}

	Point(const Point & p)
	{
		_x = p._x;
		_y = p._y;
		 cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is copied." << endl;
	}

	Point(double x , double y = 1)
	{
		_x = x;
		_y = y;
		cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is created." << endl;
	}

	void show()
	{
		std::cout << setprecision(16) << "Point : (" << _x << ", " << _y << ")" << endl;
	}

	~Point()
	{
		cout << setprecision(16) << "Point : (" << _x << ", " << _y << ") is erased." << endl;
	}

private:
	double _x;
	double _y;
};