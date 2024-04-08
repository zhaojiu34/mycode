#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void TestStack()
{
	Stack s;
	s.Init();

	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);

	cout <<"size == " << s.Size() << endl;

	while (!s.Empty())
	{
		int top = s.Top();
		cout << top << " ";
		s.Pop();
	}

	s.Destroy();
}

int main()
{
	TestStack();

	return 0;
}