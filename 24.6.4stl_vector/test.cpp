#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"

namespace Zq
{
	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;


		for (const auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

	}

	void test_vector2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int> v2 = v1;
		vector<int> v3;
		v3.resize(5, 1);

		for (const auto& e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		for (const auto& e : v3)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		for (const auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		

		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		for (const auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		auto it = v1.begin();
		while (it != v1.end())
		{
			if ((*it) % 2 == 0)
			{
				it = v1.erase(it);
			}
			else
			{
				it++;
			}
		}

		for (const auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}

int main()
{
	Zq::test_vector4();

	return 0;
}