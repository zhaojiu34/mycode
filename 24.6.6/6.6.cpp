#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

namespace Zq
{
	void test_list1()
	{
		list<int> lt1 = { 1,2,3,4,5 };
		list<int> lt2 = lt1;
		list<int> lt3 = { 10,20,30 };

		for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (const auto& e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		for (const auto& e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;

		lt3 = lt2;
		for (const auto& e : lt3)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test_list2()
	{
		list<int> lt1 = { 1,2,3,4,5 };

		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);
		lt1.push_back(40);

		for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1.push_front(10);
		lt1.push_front(20);
		lt1.push_front(30);
		lt1.push_front(70);

		for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << lt1.size() << endl;

		lt1.pop_back();
		lt1.pop_back();
		lt1.pop_back();
		lt1.pop_back();
		for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << lt1.size() << endl;


	}
}


int main()
{
	Zq::test_list2();

	return 0;
}