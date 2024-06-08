#define _CRT_SECURE_NO_WARNINGS 1

#include "stackqueue.h"

namespace Zq
{
	void test_stack()
	{
		stack<int> s;

		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);

		cout << s.size() << endl;

		while (!s.empty())
		{
			int top = s.top();
			s.pop();
			cout << top << " ";
		}
		cout << endl;

	}

	void test_queque()
	{
		queue<int> q;

		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);

		cout << q.size() << endl;

		while (!q.empty())
		{
			int front = q.front();
			q.pop();
			cout << front << " ";
		}
		cout << endl;

	}
}


int main()
{
	Zq::test_stack();
	//Zq::test_queque();

	return 0;
}