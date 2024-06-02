#define _CRT_SECURE_NO_WARNINGS 1

#include"bits/stdc++.h"
#include<iostream>

using namespace std;



class Matrix
{
private:
    int a[109][109];
    int h, l;
public:
    Matrix() { h = 0, l = 0; }
    friend Matrix operator+(Matrix& p, Matrix& q)
    {
        Matrix t;
        if (p.h != q.h || p.l != q.l) return t;
        t.l = p.l;
        t.h = p.h;
        for (int i = 0; i < p.h; ++i)
            for (int k = 0; k < p.l; ++k)
                t.a[i][k] = p.a[i][k] + q.a[i][k];
        return t;
    }
    friend Matrix operator*(Matrix& p, Matrix& q)
    {
        Matrix t;
        if (p.l != q.h) return t;
        t.h = p.h;
        t.l = q.l;
        for (int i = 0; i < t.h; ++i)
        {
            for (int k = 0; k < t.l; ++k)
            {
                int sum = 0;
                for (int v = 0; v < p.l; ++v)
                {
                    sum = sum + p.a[i][v] * q.a[v][k];
                }
                t.a[i][k] = sum;
            }
        }
        return t;
    }
    friend ostream& operator <<(ostream& out, Matrix& p)
    {
        if (p.h == 0)
        {
            out << "Error" << endl;
            return out;
        }
        for (int i = 0; i < p.h; i++)
        {
            for (int j = 0; j < p.l; j++)
            {
                if (!j)
                    out << p.a[i][j];
                else out << " " << p.a[i][j];
            }
            out << endl;
        }
        return out;
    }
    friend istream& operator >>(istream& is, Matrix& p)
    {
        is >> p.h >> p.l;
        for (int i = 0; i < p.h; ++i)
            for (int k = 0; k < p.l; ++k)
                is >> p.a[i][k];
        return is;
    }

};

int main()
{
    int cases, i;
    cin >> cases;
    for (i = 0; i < cases; i++)
    {
        Matrix A, B, C, D;
        cin >> A >> B;
        C = A + B;
        D = A * B;
        cout << "Case " << i + 1 << ":" << endl;
        cout << C << endl;
        cout << D;
    }
    return 0;
}


class Vector
{
private:
    int i, j, k;
public:
    Vector(int a = 0, int b = 0, int c = 0) : i(a), j(b), k(c) {  }
    ~Vector() {  }
public:
    Vector operator +(const Vector& v)
    {
        int ii, jj, kk;
        ii = i + v.i;
        jj = j + v.j;
        kk = k + v.k;
        return Vector(ii, jj, kk);
    }
    Vector operator -(const Vector& v)
    {
        int ii, jj, kk;
        ii = i - v.i;
        jj = j - v.j;
        kk = k - v.k;
        return Vector(ii, jj, kk);
    }
    Vector operator *(const Vector& v)
    {
        int ii, jj, kk;
        ii = j * v.k - v.j * k;
        jj = k * v.i - i * v.k;
        kk = i * v.j - v.i * j;
        return Vector(ii, jj, kk);
    }
    Vector operator *(int n)
    {
        int ii, jj, kk;
        ii = i * n;
        jj = j * n;
        kk = k * n;
        return Vector(ii, jj, kk);
    }
    friend ostream& operator <<(ostream& os, const Vector& v)
    {
        if (v.i > 0)
            os << v.i << "i";
        if (v.i < 0)
            os << v.i << "i";
        if (v.j > 0 && v.i != 0)
            os << "+" << v.j << "j";
        if (v.j > 0 && v.i == 0)
            os << v.j << "j";
        if (v.j < 0)
            os << v.j << "j";
        if (v.k > 0 && (v.i != 0 || v.j != 0))
            os << "+" << v.k << "k";
        if (v.k > 0 && v.i == 0 && v.j == 0)
            os << v.k << "k";
        if (v.k < 0)
            os << v.k << "k";
        if (v.i == 0 && v.j == 0 && v.k == 0)
            os << 0;
        return os;
    }
    friend istream& operator >>(istream& is, Vector& v)
    {
        is >> v.i >> v.j >> v.k;
        return is;
    }

};
int main()
{
    Vector vec1, vec2, vec3;
    int cases, n;
    cin >> cases;
    cout << "vect+vec2\tn*vec1\tvec1*vec2\n";
    for (int i = 0; i < cases; i++)
    {
        cin >> vec1 >> vec2 >> n;
        vec3 = vec1 + vec2;
        cout << vec3 << "\t";
        vec3 = vec1 * n;
        cout << vec3 << "\t";
        vec3 = vec1 * vec2;
        cout << vec3 << endl;
    }
    return 0;
}

class MaxValue
{
public:
    void append(int x)
    {
        vv.push_back(x);
    }

    int getMax()
    {
        int max = vv[0];

        for (size_t i = 0; i < vv.size(); i++)
        {
            if (max < vv[i])
                max = vv[i];
        }
        return max;
    }

private:
    vector<int> vv;
};
int main()
{
    int a;
    MaxValue test;
    cin >> a;
    while (a != 0)
    {
        test.append(a);
        cin >> a;
    }
    cout << test.getMax() << endl;
    return 0;
}

class Point
{
public:
    friend ostream& operator<<(ostream& out, Point& p);
    Point(int x = 0, int y = 0)
        :_x(x)
        , _y(y)
    {}

private:
    int _x;
    int _y;
};

ostream& operator<<(ostream& out, Point& p)
{
    out << p._x << " " << p._y;

    return out;
}

template<class T>
class Data
{
public:
    Data(T x = T())
    {
        _data = x;
    }

    void show()
    {
        cout << _data << endl;
    }

private:
    T _data;
};

int main()
{
    string n;
    int x, y, d;
    char c;
    cin >> n;
    cin >> x >> y >> d;
    cin >> c;
    Point p(x, y);
    Data<char> aChar(c);
    Data<int> anInt(d);
    Data<Point> aPoint(p);
    Data<string> aString(n);
    aChar.show();
    anInt.show();
    aString.show();
    aPoint.show();
    return 0;
}

class Data
{
public:
    T value;
public:
    Data() { value = (T)0; }
    Data(T x) :value(x) {}
    bool operator < (const Data& t)
    {
        if (value < t.value)
            return true;
        else
            return false;
    }
    bool operator > (const Data& t)
    {
        if (value > t.value)
            return true;
        else
            return false;
    }
    friend ostream& operator << (ostream& os, const Data& x)
    {
        os << setprecision(2) << fixed << x.value;
        return os;
    }
    Data operator + (const Data& x)
    {
        return value + x.value;
    }
    void setValue(T x)
    {
        value = x;
    }
    //friend class GetResult;
};
template<typename T>
class GetResult
{
    //friend class Data;
public:
    static Data<T> getSum(Data<T>* arr, int num)
    {
        Data<T> sum;
        for (int i = 0; i < num; i++)
        {
            sum = sum + arr[i];
        }
        return sum;
    }
    static Data<T> getMax(Data<T>* arr, int num)
    {
        Data<T> maxx;
        maxx.value = arr[0].value;
        for (int i = 0; i < num; i++)
        {
            if (maxx < arr[i])
            {
                maxx.value = arr[i].value;
            }
        }
        return maxx;
    }
    static Data<T> getMin(Data<T>* arr, int num)
    {
        Data<T> minn;
        minn.value = arr[0].value;
        for (int i = 0; i < num; i++)
        {
            if (minn > arr[i])
            {
                minn.value = arr[i].value;
            }
        }
        return minn;
    }
};
int main()
{
    Data<int> iData[1001];
    Data<double> dData[1001];
    int cases, num;
    char ch;
    int u;
    double v;
    Data<int> a(10), b(20);
    Data<double> c(3.14), d(-4.1);
    cout << "a + b = " << (a + b) << endl;
    cout << "max(a, b) = " << (a > b ? a : b) << endl;
    cout << "min(a, b) = " << (a < b ? a : b) << endl;
    cout << "c + d = " << (c + d) << endl;
    cout << "max(c, d) = " << (c > d ? c : d) << endl;
    cout << "min(c, d) = " << (c < d ? c : d) << endl;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> ch;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            if (ch == 'i')
            {
                cin >> u;
                iData[j].setValue(u);
            }
            else if (ch == 'd')
            {
                cin >> v;
                dData[j].setValue(v);
            }
        }
        if (ch == 'i')
        {
            cout << GetResult<int>::getMax(iData, num);
            cout << " " << GetResult<int>::getMin(iData, num);
            cout << " " << GetResult<int>::getSum(iData, num) << endl;
        }
        else if (ch == 'd')
        {
            cout << GetResult<double>::getMax(dData, num);
            cout << " " << GetResult<double>::getMin(dData, num);
            cout << " " << GetResult<double>::getSum(dData, num) << endl;
        }
    }
    return 0;
}
