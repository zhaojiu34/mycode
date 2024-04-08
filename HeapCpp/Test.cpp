#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void TestHeap()
{
	Heap h;
	int a[] = { 10,5,6,4,7,9,8,3,1,2 };
	h.Creat(a, sizeof(a) / sizeof(int));

}

int main()
{
	TestHeap();

	return 0;
}