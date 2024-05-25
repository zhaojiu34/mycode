#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include "String.h"

namespace Zq
{
	void test_string1()
	{
		string s1("hello world!");
		string s2 = s1;
		string s3 = "xxxxxxxxx";

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		s1 += 'x';
		s1 += 'c';
		s1 += 'a';
		cout << s1 << endl;

		/*s1 += "my string";
		cout << s1 << endl;*/

		s1 += " my class string ";
		//s1.append("xxxxxxx");
		cout << s1 << endl;
		s1.append("xxxxxxxxx");
		cout << s1 << endl;

		for (auto& e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s;
		cin >> s;
		cout << s;
	}
	void Test()
	{
		string s1;
		cin >> s1;
		cout << s1;

		string s2 = "hello";
		cout << s1.c_str() << endl;
	}
}

int main()
{

	Zq::test_string1();
	return 0;
}

