#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"


void TestHeap()
{
	Heap hp;
	int a[] = { 70,90,65,20,10,95,30,14 };

	HeapCreat(&hp, a, sizeof(a) / sizeof(int));

	while (!HeapEmpty(&hp))
	{
		int top = HeapTop(&hp);
		printf("%d ", top);

		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

int main()
{
	TestHeap();
	return 0;
}