#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

namespace Zq
{
	void test_string1()
	{
		string s1 = "hello world";
		cout << s1.c_str() << endl;

		string s2 = s1;
		for (const auto& e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		string s3 = "xxxxxxxxxxx";
		for (const auto& e : s3)
		{
			cout << e << " ";
		}
		cout << endl;

		s1 = s3;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1 = "hello world";

		string s2 = s1;
		for (const auto& e : s2)
		{
			cout << e;
		}
		cout << endl;

		/*s2 += "xxxxxxxxx";
		for (const auto& e : s2)
		{
			cout << e;
		}
		cout << endl;*/

		s2 += 'a';
		s2 += 'b';
		s2 += 'c';
		s2 += 'd';
		s2 += 'e';
		s2 += "fghijklmnopqrst";
		for (const auto& e : s2)
		{
			cout << e;
		}
		cout << endl;


		s2.erase(5);
		for (const auto& e : s2)
		{
			cout << e;
		}
		cout << endl;
	}

	void test_string3()
	{
		string s1 = "hello world";
		cout << s1.find('h') << endl;
		cout << s1.find("ello") << endl;
	}
}

int main()
{
	Zq::test_string3();

	return 0;
}