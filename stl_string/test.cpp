#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

namespace aa
{
	void test_string1()
	{
		string s1 = "hello world";
		string s2 = "xxxxxxxxxx";
		s1 = s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3 (s2);

		cout << s3.c_str()<<endl;

		//cout << (s3 == s2) << endl;

	}
	
	void test_string2()
	{
		string s1 = "hello world";
		string s2(s1);

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		for (auto& e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		auto it1 = s1.begin();
		while (it1 != s1.end())
		{
			cout << *it1 << " ";
			*it1 += 3;
			it1++;
		}
		cout << endl;

		cout << s1.c_str() << endl;
	}

	void test_string3()
	{
		string s1 = "hello world";
		string s2 = "xxxxxxxxx";
		string s3 = s2;

		s1 += " hello";
		cout << s1.c_str() << endl;
		
		s1.append(" world!");
		cout << s1.c_str() << endl;

		s2 += 'c';
		s2.push_back('a');
		s2.push_back('b');
		s2.push_back('d');
		cout << s2.c_str() << endl;

		s1.insert(0, "I said ");
		cout << s1.c_str() << endl;

		s1.erase(10);
		cout << s1.c_str() << endl;

		s2.erase(5,9);
		cout << s2.c_str() << endl;
	
	}

	void test_string4()
	{
		string s1 = "xxxxxxxx123456";
		string s2 = "hello world";

		cout << s1.find('9') << endl;
		cout << s2.find("world",1) << endl;

		string sub = s1.sub(5,15);
		cout << sub.c_str() << endl;

	}

	void test_string5()
	{
		string s1;
		cin >> s1;
		cout << s1 << endl;

		/*string s2 = "i said hello world ";
		cout << s2<<endl;*/

	}
}



int main()
{
	aa::test_string1();

	return 0;
}