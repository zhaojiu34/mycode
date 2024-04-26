#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"



void Test1()
{
	Date d1(2024, 10, 3);
	Date d2(2024, 10, 3);
	Date d3(2023, 10, 3);
	Date d4(2025, 10, 3);
	cout << (d1 == d2) << endl;
	cout << (d1 >= d3) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 <= d4) << endl;
	cout << (d1 < d3) << endl;
}

void Test2()
{
	Date d(2024, 4, 26);
	/*Date d1 = d.operator+=(200);
	d1.Print();*/

	Date d2 = d.operator-=(2000);
	d2.Print();

}

void Test3()
{
	Date d1(2024, 4, 26);
	d1++;
	d1.Print();
	d1--;
	d1.Print();

	Date d3 = d1.operator--(1);
	d3.Print();
}

void Test()
{
	Date d1(2024, 4, 26);
	Date d2(2020, 5,1);

	cout << (d1 - d2) << endl;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test();
	return 0;
}