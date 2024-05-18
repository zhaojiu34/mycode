//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//using namespace::std;
//
//int len(const char* a)
//{
//    int i;
//    for (i = 0; a[i]; i++);
//    return i;
//}
//void cpy(char* a, const char* b)
//{
//    int i;
//    for (i = 0; b[i]; i++)
//        a[i] = b[i];
//    a[i] = 0;
//}
//
//class STR
//{
//private:
//    int len_, siz_;
//    char* s_;
//public:
//    STR() : len_(0), siz_(0), s_(NULL) { }
//    STR(const char* str) : len_(len(str)), siz_(2 * len_)
//    {
//        s_ = new char[siz_];
//        cpy(s_, str);
//    }
//    ~STR() { delete[] s_; }
//
//    void putline() const
//    {
//        for (int i = 0; i < len_; i++)
//            cout << s_[i];
//        cout << endl;
//    }
//
//    int length() { return len_; }
//
//    friend STR operator+(const STR& s, const STR& t)
//    {
//        STR res;
//        res.len_ = s.len_ + t.len_;
//        res.siz_ = res.len_ * 2;
//        res.s_ = new char[res.siz_];
//        int i;
//        for (i = 0; i < s.len_; i++)
//            res.s_[i] = s.s_[i];
//        for (int j = i; j <= i + t.len_; j++)
//            res.s_[j] = t.s_[j - s.len_];
//        return res;
//    }
//
//    STR& operator+=(const STR& s)
//    {
//        int len = len_ + s.len_;
//        siz_ = len * 2;
//        char* str = new char[siz_];
//        for (int i = 0; i < len_; i++)
//            str[i] = s_[i];
//        for (int i = len_; i <= len; i++)
//            str[i] = s.s_[i - len_];
//        delete[] s_;
//        s_ = str;
//        len_ = len;
//        return *this;
//    }
//};
//int main()
//{
//    STR e;
//    STR h("Hello World!");
//    STR he = e + h;
//    cout << he.length() << " ";
//    he.putline();
//    cout << e.length() << " ";
//    e.putline();
//    cout << h.length() << " ";
//    h.putline();
//    e += h;
//    cout << e.length() << " ";
//    e.putline();
//    cout << h.length() << " ";
//    h.putline();
//
//    char s1[100001], s2[100001];
//    while (gets(s1) != NULL && gets(s2) != NULL)
//    {
//        STR str1(s1), str2(s2);
//        STR str = str1 + str2;
//        cout << str.length() << " ";
//        str.putline();
//        cout << str1.length() << " ";
//        str1.putline();
//        cout << str2.length() << " ";
//        str2.putline();
//        str2 += str1;
//        cout << str2.length() << " ";
//        str2.putline();
//        cout << str1.length() << " ";
//        str1.putline();
//    }
//}
//
//
//
//int rec = 0;
//class  STR
//{
//private:
//    char* a;
//public:
//    STR()
//    {
//        a = new char[1];
//        a[0] = 0;
//    }
//    int length()
//    {
//        int i = 0;
//        while (a[i++] != 0);
//        return i - 1;
//    }
//    STR(const char* p)
//    {
//        int i = 0;
//        while (p[i++] != 0);
//        a = new char[i];
//        for (i = 0; p[i] != 0; ++i)
//        {
//            a[i] = p[i];
//        }
//        a[i] = 0;
//    }
//    void putline()
//    {
//        cout << a << endl;
//    }
//};
//int main()
//{
//    STR e;
//    STR h("Hello World!");
//    char s[100001];
//    cout << e.length() << " ";
//    e.putline();
//    cout << h.length() << " ";
//    h.putline();
//    while (gets(s) != NULL)
//    {
//        STR str(s);
//        cout << str.length() << " ";
//        str.putline();
//    }
//}
//
//class Date
//{
//public:
//    Date(int y = 1, int m = 1, int d = 1)
//    {
//        year_ = y;
//        month_ = m;
//        day_ = d;
//        cout << "CREATE Date : (" << year_ << ", " << month_ << ", " << day_ << ")" << endl;
//
//    }
//    Date(const Date& another)
//    {
//        year_ = another.year_;
//        month_ = another.month_;
//        day_ = another.day_;
//        cout << "COPY   Date : (" << year_ << ", " << month_ << ", " << day_ << ")" << endl;
//    }
//    void setDate(int y, int m, int d)
//    {
//        year_ = y;
//        month_ = m;
//        day_ = d;
//    }
//    void showDate()
//    {
//        printf("%04d-%02d-%02d", year_, month_, day_);
//    }
//    void show()
//    {
//        printf("(%d, %d, %d) ", year_, month_, day_);
//    }
//    void year(int y)
//    {
//        year_ = y;
//    }
//    int year() const
//    {
//        return year_;
//    }
//    void month(int m)
//    {
//        month_ = m;
//    }
//    int month() const
//    {
//        return month_;
//    }
//    void day(int d)
//    {
//        day_ = d;
//    }
//    int day() const
//    {
//        return day_;
//    }
//private:
//    int year_, month_, day_;
//};
//
//class Time
//{
//public:
//    Time(int h = 0, int m = 0, int s = 0)
//    {
//        hour_ = h;
//        minute_ = m;
//        second_ = s;
//        cout << "CREATE Time : (" << hour_ << ", " << minute_ << ", " << second_ << ")" << endl;
//    }
//    Time(const Time& another)
//    {
//        hour_ = another.hour_;
//        minute_ = another.minute_;
//        second_ = another.second_;
//        cout << "COPY   Time : (" << hour_ << ", " << minute_ << ", " << second_ << ")" << endl;
//    }
//    void setTime(int h, int m, int s)
//    {
//        hour_ = h;
//        minute_ = m;
//        second_ = s;
//    }
//    void showTime()
//    {
//        printf("%02d:%02d:%02d", hour_, minute_, second_);
//    }
//    void show()
//    {
//        printf("(%d, %d, %d)\n", hour_, minute_, second_);
//    }
//    void hour(int h)
//    {
//        hour_ = h;
//    }
//    int hour() const
//    {
//        return hour_;
//    }
//    void second(int s)
//    {
//        second_ = s;
//    }
//    int second() const
//    {
//        return second_;
//    }
//    void minute(int m)
//    {
//        minute_ = m;
//    }
//    int minute() const
//    {
//        return minute_;
//    }
//
//private:
//    int hour_, minute_, second_;
//};
//
//class DateTime
//{
//public:
//    DateTime(int y = 1, int m = 1, int d = 1, int hh = 0, int mm = 0, int ss = 0) :date(y, m, d), time(hh, mm, ss)
//    {
//        printf("CREATE DateTime : (%d, %d, %d) (%d, %d, %d)\n", y, m, d, hh, mm, ss);
//    }
//    DateTime(const Date& anotherDate, const Time& anotherTime) :date(anotherDate), time(anotherTime)
//    {
//        cout << "CREATE DateTime : ";
//        date.show();
//        time.show();
//    }
//    DateTime(const DateTime& another) :time(another.time), date(another.date)
//    {
//        cout << "COPY   DateTime : ";
//        date.show();
//        time.show();
//
//    }
//    DateTime& setDateTime(int y, int m, int d, int hh, int mm, int ss)
//    {
//        date.setDate(y, m, d);
//        time.setTime(hh, mm, ss);
//        return *this;
//    }
//    void showDateTime()
//    {
//        date.showDate();
//        cout << " ";
//        time.showTime();
//    }
//    void year(int y)
//    {
//        date.year(y);
//    }
//    int year() const
//    {
//        return date.year();
//    }
//    void month(int m)
//    {
//        date.month(m);
//    }
//    int month() const
//    {
//        return date.month();
//    }
//    void day(int d)
//    {
//        date.day(d);
//    }
//    int day() const
//    {
//        return date.day();
//    }
//    void hour(int h)
//    {
//        time.hour(h);
//    }
//    int hour() const
//    {
//        return time.hour();
//    }
//    void second(int s)
//    {
//        time.second(s);
//    }
//    int second() const
//    {
//        return time.second();
//    }
//    void minute(int m)
//    {
//        time.minute(m);
//    }
//    int minute() const
//    {
//        return time.minute();
//    }
//private:
//    Time time;
//    Date date;
//};
//int main()
//{
//    const Date date(1000, 10, 10), dt(date);
//    const Time time(1, 1, 1), tm(time);
//    DateTime date_time(dt, tm);
//    const DateTime cnt(date_time);
//    cout << "DateTime : " << cnt.year() << " " << cnt.month() << " " << cnt.day();
//    cout << " " << cnt.hour() << " " << cnt.minute() << " " << cnt.second();
//    cout << endl;
//    int cases;
//    cin >> cases;
//    for (int ca = 0; ca < cases; ca++)
//    {
//        int year, month, day;
//        cin >> year >> month >> day;
//        int hour, minute, second;
//        cin >> hour >> minute >> second;
//        date_time.year(year);
//        date_time.month(month);
//        date_time.day(day);
//        date_time.hour(hour);
//        date_time.minute(minute);
//        date_time.second(second);
//        date_time.showDateTime();
//        cout << endl;
//    }
//}
//
//class Date
//{
//public:
//    Date(int y = 1, int m = 1, int d = 1)
//    {
//        year = y;
//        month = m;
//        day = d;
//        cout << "CREATE Date : (" << year << ", " << month << ", " << day << ")" << endl;
//
//    }
//    Date(const Date& another)
//    {
//        year = another.year;
//        month = another.month;
//        day = another.day;
//    }
//    void setDate(int y, int m, int d)
//    {
//        year = y;
//        month = m;
//        day = d;
//    }
//    void showDate()
//    {
//        printf("%04d-%02d-%02d", year, month, day);
//    }
//private:
//    int year, month, day;
//};
//
//class Time
//{
//public:
//    Time(int h = 0, int m = 0, int s = 0)
//    {
//        hour = h;
//        minute = m;
//        second = s;
//        cout << "CREATE Time : (" << hour << ", " << minute << ", " << second << ")" << endl;
//    }
//    Time(const Time& another)
//    {
//        hour = another.hour;
//        minute = another.minute;
//        second = another.second;
//    }
//    void setTime(int h, int m, int s)
//    {
//        hour = h;
//        minute = m;
//        second = s;
//    }
//    void showTime()
//    {
//        printf("%02d:%02d:%02d", hour, minute, second);
//    }
//private:
//    int hour, minute, second;
//};
//
//class DateTime
//{
//public:
//    DateTime(int y = 1, int m = 1, int d = 1, int hh = 0, int mm = 0, int ss = 0) :date(y, m, d), time(hh, mm, ss)
//    {
//        printf("CREATE DateTime : (%d, %d, %d, %d, %d, %d)\n", y, m, d, hh, mm, ss);
//    }
//    DateTime(const Date& anotherDate, const Time& anotherTime) :date(anotherDate), time(anotherTime) {}
//    DateTime& setDateTime(int y, int m, int d, int hh, int mm, int ss)
//    {
//        date.setDate(y, m, d);
//        time.setTime(hh, mm, ss);
//        return *this;
//    }
//    void showDateTime()
//    {
//        date.showDate();
//        cout << " ";
//        time.showTime();
//    }
//private:
//    Time time;
//    Date date;
//};
//int main()
//{
//    DateTime date_time;
//    date_time.showDateTime();
//    cout << endl;
//    int cases;
//    cin >> cases;
//    for (int ca = 0; ca < cases; ca++)
//    {
//        int year, month, day;
//        cin >> year >> month >> day;
//        int hour, minute, second;
//        cin >> hour >> minute >> second;
//        date_time.setDateTime(year, month, day, hour, minute, second);
//        date_time.showDateTime();
//        cout << endl;
//    }
//}