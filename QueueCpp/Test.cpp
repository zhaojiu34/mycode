#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void TestQueue()
{
	Queue q;
	q.Init();

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	printf("size == %d\n", q.Size());

	while (!q.Empty())
	{
		int front = q.Front();
		q.Pop();
		printf("%d ", front);
	}

	q.Destroy();
}

int main()
{

	TestQueue();

	return 0;
}