#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

namespace Zq
{
	void test_list1()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		/*for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1.push_front(1);
		lt1.push_front(2);
		lt1.push_front(3);
		lt1.push_front(4);
		for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;*/

		lt1.pop_back();
		lt1.pop_back();
		lt1.pop_back();
		for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		/*lt1.pop_front();
		lt1.pop_front();
		lt1.pop_front();
		for (const auto& e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;*/

	}

	void test_list2()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int> lt2 = lt1;
		for (const auto& e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt3(5, 10);
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



}

int main()
{
	Zq::test_list2();

	return 0;
}


