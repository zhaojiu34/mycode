#define _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//#include<iomanip>
//#include<cmath>
//#include<cstring>
//#include<ctype.h>
//using namespace std;
//int sum = 0;
//
//class Time
//{
//private:
//    int hh, mm, ss, up, k;
//public:
//    Time() :hh(0), mm(0), ss(0)
//    {
//        ++sum;
//    }
//    Time(int h, int m, int s)
//    {
//        hh = h;
//        mm = m;
//        ss = s;
//        ++sum;
//
//    }
//    Time(const Time& t)
//    {
//        hh = t.hh;
//        mm = t.mm;
//        ss = t.ss;
//        ++sum;
//
//    }
//    int hour()const { return hh; }
//    int minute()const { return mm; }
//    int second()const { return ss; }
//    void hour(int h) { hh = h; }
//    void minute(int m) { mm = m; }
//    void second(int s) { ss = s; }
//    const Time& getTime()
//        const {
//        return *this;
//    }
//    Time& setTime(int h, int m, int s)
//    {
//        hh = h;
//        mm = m;
//        ss = s;
//        return *this;
//    }
//    const Time& setTime(const Time& t)
//    {
//        hh = t.hh;
//        mm = t.mm;
//        ss = t.ss;
//        return *this;
//    }
//    Time inputTime()
//    {
//        cin >> hh >> mm >> ss;
//        return *this;
//    }
//    const void showTime()
//        const {
//        if (hh >= 24 || mm >= 60 || ss >= 60 || hh < 0 || mm < 0 || ss < 0) cout << "Time error" << endl;
//        else cout << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << endl;
//    }
//    Time operator +=(int t)
//    {
//        if (hh * 3600 + mm * 60 + ss >= 24 * 3600 || mm > 59 || ss > 59 || hh < 0 || ss < 0 || mm < 0)
//            return *this;
//        k = (hh * 3600 + mm * 60 + ss + t) % (24 * 3600);
//        hh = k / 3600;
//        mm = (k - hh * 3600) / 60;
//        ss = k - hh * 3600 - mm * 60;
//        return *this;
//    }
//    Time operator -=(int t)
//    {
//        if (hh * 3600 + mm * 60 + ss >= 24 * 3600 || mm > 59 || ss > 59 || hh < 0 || ss < 0 || mm < 0)
//            return *this;
//        k = (hh * 3600 + mm * 60 + ss - t) % (24 * 3600);
//        if (k < 0) k = 24 * 3600 + k;
//        hh = k / 3600;
//        mm = (k - hh * 3600) / 60;
//        ss = k - hh * 3600 - mm * 60;
//        return *this;
//    }
//};


#include <iostream>
#include <algorithm>
#include <iomanip>


//class Time {
//    int a, b, c;
//public:
//    friend ostream& operator<< (ostream&, const Time&);
//    friend istream& operator>> (istream&, Time&);
//    Time& operator++ () {
//        if (this->a < 0 || this->a > 23 || this->b < 0 || this->b > 59 || this->c < 0 || this->c > 59)
//            return *this;
//        ++(this->c);
//        if (this->c > 59) {
//            (this->c) -= 60;
//            (this->b)++;
//        }
//        if (this->b > 59) {
//            (this->b) -= 60;
//            (this->a)++;
//        }
//        if (this->a > 23)
//            (this->a) -= 24;
//        return *this;
//    }
//    Time& operator-- () {
//        if (this->a < 0 || this->a > 23 || this->b < 0 || this->b > 59 || this->c < 0 || this->c > 59)
//            return *this;
//        --(this->c);
//        if (this->c < 0) {
//            (this->c) += 60;
//            (this->b)--;
//        }
//        if (this->b < 0) {
//            (this->b) += 60;
//            (this->a)--;
//        }
//        if (this->a < 0)
//            (this->a) += 24;
//
//        return *this;
//    }
//    Time operator++ (int) {
//        if (this->a < 0 || this->a > 23 || this->b < 0 || this->b > 59 || this->c < 0 || this->c > 59)
//            return *this;
//
//        Time t(*this); (this->c)++;
//        if (this->c > 59) {
//            (this->c) -= 60;
//            (this->b)++;
//        }
//        if (this->b > 59) {
//            (this->b) -= 60;
//            (this->a)++;
//        }
//        if (this->a > 23)
//            (this->a) -= 24;
//
//        return t;
//    }
//    Time operator-- (int) {
//        if (this->a < 0 || this->a > 23 || this->b < 0 || this->b > 59 || this->c < 0 || this->c > 59)
//            return *this;
//        Time t(*this);
//        (this->c)--;
//        if (this->c < 0) {
//            (this->c) += 60;
//            (this->b)--;
//        }
//        if (this->b < 0) {
//            (this->b) += 60;
//            (this->a)--;
//        }
//        if (this->a < 0)
//            (this->a) += 24;
//
//        return t;
//    }
//};
//
//ostream& operator<< (ostream& os, const Time& t)
//{
//    if (t.a < 0 || t.a > 23 || t.b < 0 || t.b > 59 || t.c < 0 || t.c > 59)
//        os << "error!!!";
//    else
//        os << setw(2) << setfill('0') << fixed << t.a << ':' \
//        << setw(2) << setfill('0') << fixed << t.b << ':' \
//        << setw(2) << setfill('0') << fixed << t.c;
//    return os;
//}
//
//istream& operator>> (istream& is, Time& t)
//{
//    is >> t.a >> t.b >> t.c;
//    return is;
//}


//#include<map>
//#include<list>
//#include<cmath>
//#include<queue>
//#include<stack>
//#include<cstdio>
//#include<vector>
//#include<iomanip> 
//#include<cstring>
//#include<iterator>
//#include<iostream>
//#include<algorithm>
//#define R register 
//#define LL long long 
//#define pi 3.141
//#define mod 10000
//#define INF 1400000000
//using namespace std;
//
///*class box{
//	protected:
//		int volume;
//		int height, lenth, breadth;
//	public:
//		void set_lenth(int len){
//			lenth = len;
//		}
//		void set_breadth(int bre){
//			breadth = bre;
//		}
//		void set_height(int he){
//			height = he;
//		}
//};
//class small_box : public box{
//	public:
//		int get_volume();
//};
//
//inline int small_box::get_volume(){
//	volume = height * lenth * breadth;
//	return volume;
//}
//
//int main(){
//	small_box my_box;
//	my_box.box::set_lenth(1), my_box.box::set_breadth(2), my_box.box::set_height(3);
//	printf("%d", my_box.get_volume());
//	return 0;
//}*/
//
//class Date {
//private:
//	int Dyear, Dmonth, Dday;
//public:
//	Date(int year, int month, int day) {
//		Dyear = year, Dmonth = month, Dday = day;
//	}
//	void showDate() {
//		printf("%d-%02d-%02d", Dyear, Dmonth, Dday);
//	}
//};
//class Time {
//private:
//	int Dhour, Dminute, Dsecond;
//public:
//	Time(int hour, int minute, int second) {
//		Dhour = hour, Dminute = minute, Dsecond = second;
//	}
//	void showTime() {
//		printf("%02d:%02d:%02d", Dhour, Dminute, Dsecond);
//	}
//};


//class Date
//{
//public:
//    Date(int y = 1, int m = 1, int d = 1)
//    {
//        year = y;
//        month = m;
//        day = d;
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
//    DateTime(int y, int m, int d, int hh, int mm, int ss) :date(y, m, d), time(hh, mm, ss) {}
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
//    Date date;
//    Time time;
//};



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



//using namespace std;
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

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace::std;

int len(const char* a)
{
    int i;
    for (i = 0; a[i]; i++);
    return i;
}
void cpy(char* a, const char* b)
{
    int i;
    for (i = 0; b[i]; i++)
        a[i] = b[i];
    a[i] = 0;
}

class STR
{
private:
    int len_, siz_;
    char* s_;
public:
    STR() : len_(0), siz_(0), s_(NULL) { }
    STR(const char* str) : len_(len(str)), siz_(2 * len_)
    {
        s_ = new char[siz_];
        cpy(s_, str);
    }
    ~STR() { delete[] s_; }

    void putline() const
    {
        for (int i = 0; i < len_; i++)
            cout << s_[i];
        cout << endl;
    }

    int length() { return len_; }

    friend STR operator+(const STR& s, const STR& t)
    {
        STR res;
        res.len_ = s.len_ + t.len_;
        res.siz_ = res.len_ * 2;
        res.s_ = new char[res.siz_];
        int i;
        for (i = 0; i < s.len_; i++)
            res.s_[i] = s.s_[i];
        for (int j = i; j <= i + t.len_; j++)
            res.s_[j] = t.s_[j - s.len_];
        return res;
    }

    STR& operator+=(const STR& s)
    {
        int len = len_ + s.len_;
        siz_ = len * 2;
        char* str = new char[siz_];
        for (int i = 0; i < len_; i++)
            str[i] = s_[i];
        for (int i = len_; i <= len; i++)
            str[i] = s.s_[i - len_];
        delete[] s_;
        s_ = str;
        len_ = len;
        return *this;
    }
};