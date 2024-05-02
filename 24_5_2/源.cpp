#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//求1+2+3+.....+n
class Solution {

    class Sum
    {
    public:
        Sum()
        {
            _ret += _i;
            _i++;
        }

    };

public:
    int Sum_Solution(int n)
    {
        Sum arr[n];

        return _ret;
    }

private:
    static int _i;
    static int _ret;
};

int Solution::_i = 1;
int Solution::_ret = 0;

//计算日期到天数的转换
int main()
{
    int a[13] = { 0,31, 59,90,120,151,181,212,243,273,304,334,365 };

    int year = 0, month = 0, day = 0;
    cin >> year >> month >> day;

    if (month - 1 >= 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
    {
        cout << a[month - 1] + day + 1;
    }

    else {
        cout << a[month - 1] + day;
    }

    return 0;
}


////日期差值
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    int GetMonthDay(int year, int month)
//    {
//        int a[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//        {
//            return  a[month] + 1;
//        }
//        else {
//            return a[month];
//        }
//    }
//
//    bool operator==(Date d)
//    {
//        return _year == d._year
//            && _month == d._month
//            && _day == d._day;
//    }
//
//    bool operator!=(Date d)
//    {
//        return !((*this) == d);
//    }
//
//    bool operator<(Date d)
//    {
//        if (_year < d._year)
//        {
//            return true;
//        }
//
//        else if (_year == d._year)
//        {
//            if (_month < d._month)
//            {
//                return true;
//            }
//            else if (_month == d._month)
//            {
//                return _day < d._day;
//            }
//        }
//
//        return false;
//    }
//
//    Date operator+=(int day)
//    {
//        _day += 1;
//
//        while (_day >= GetMonthDay(_year, _month))
//        {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//            if (_month > 12)
//            {
//                _month = 1;
//                _year++;
//            }
//        }
//
//        return (*this);
//    }
//
//    int operator-(Date d)
//    {
//        Date dgreater = (*this);
//        Date dsmall = d;
//
//        if ((*this) < d)
//        {
//            dgreater = d;
//            dsmall = (*this);
//        }
//
//        int gap = 0;
//        while (dsmall != dgreater)
//        {
//            gap++;
//            dsmall += 1;
//        }
//
//        return gap + 1;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    int year1 = 0, month1 = 0, day1 = 0;
//    scanf("%4d %2d %2d", &year1, &month1, &day1);
//
//    int year2 = 0, month2 = 0, day2 = 0;
//    scanf("%4d %2d %2d", &year2, &month2, &day2);
//
//    Date d1(year1, month1, day1);
//    Date d2(year2, month2, day2);
//
//    cout << (d2 - d1) << endl;
//    return 0;
//}


class Date
{
public:
    Date(int year = 0, int day = 0, int month = 0)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    int GetMonthDay(int _year, int _month)
    {
        int arry[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

        if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0))
        {
            return arry[_month] + 1;
        }
        else {
            return arry[_month];
        }
    }

    Date operator+=(int day)
    {
        _day += day;

        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month++;

            if (_month > 12)
            {
                _month = 1;
                _year++;
            }

        }

        return (*this);
    }

    int Year()
    {
        return _year;
    }

    int Month()
    {
        return _month;
    }

    int Day()
    {
        return _day;
    }

private:
    int _year;
    int _month;
    int _day;
};

//打印日期
//int main()
//{
//    int year = 0, month = 1, day = 0;
//    while ((scanf("%d %d", &year, &day)) != EOF)
//    {
//        Date d(year, 0, 1);
//
//        d += day;
//
//        printf("%04d-%02d-%02d\n", d.Year(), d.Month(), d.Day());
//
//    }
//
//}

//日期累加
int main()
{
    int year = 0, month = 0, day1 = 0, day2 = 0;
    int n = 0;
    cin >> n;

    while (n--)
    {
        cin >> year >> month >> day1 >> day2;

        Date d(year, month, day1);

        d += day2;
        printf("%04d-%02d-%02d\n", d.Year(), d.Month(), d.Day());
    }
}