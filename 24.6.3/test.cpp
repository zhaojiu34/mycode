#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

namespace Zq
{
	void test_string1()
	{
		string s1;
		string s2 = "hello world";
		string s3 = "xxxxxxxxx";
		string s4 = s2;
		string s5 = "abcdefgh";

		s1 = "yyyyyyyyyy";

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
		cout << s4.c_str() << endl;
		cout << s5.c_str() << endl;
	}

	void test_string2()
	{
		string s1;
		string s2 = "hello world";
		string s3 = "xxxxxxxxx";
		string s5 = "abcdefgh";

		s2 = s3;

		for (size_t i = 0; i < s2.size(); i++)
		{
			cout << s2[i] << " ";
		}
		cout << endl;

		for (const auto& e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		for (size_t i = 0; i < s5.size(); i++)
		{
			cout << s5[i] << " ";
		}
		cout << endl;

		for (const auto& e : s5)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_string3()
	{
		string s2 = "hello world";
		string s3 = "xxxxxxxxx";

		cout << (s2 <= s3)<<endl;

		s2 = s3;
		cout << (s2 == s3) << endl;

	}

	void test_string4()
	{
		string s1;
		string s2 = "hello world";
		string s3 = "xxxxxxxxx";

		s1.push_back('a');
		s1.push_back('b');
		s1.push_back('c');
		s1.push_back('d');
		s1.push_back('e');
		s1.append(" hello world ");
		s1.insert(0, "xxxxxxx");
		s1.insert(0, 'm');

		for (const auto& e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
		
		s1.erase(5,100);
		for (const auto& e : s1)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test_string5()
	{
		string s1;
		s1.push_back('a');
		s1.push_back('b');
		s1.push_back('c');
		s1.push_back('d');
		s1.push_back('e');
		s1.append(" hello world ");

		cout << s1.find('a') << endl;
		cout << s1.find(0, "hello world") << endl;
		cout << s1.find(0,"xxxxx")<<endl;
	}

	void test_string6()
	{
		string s1 = "hello world xxxxxxxxxxx";

		string sub = s1.sub(5,5);
		for (const auto& e : sub)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_string7()
	{
		string s1 = "xxxxxxxxxxxxxxx";

		string s2;
		cin >> s2;
		
		cout << s1 << endl;
		cout << s2 << endl;
	}

}



int main()
{
	Zq::test_string7();

	return 0;
}