#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void TestStack()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 4);
	StackPush(&st, 4);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);

	int size = StackSize(&st);
	printf("size : %d \n", size);

	while (!StackEmpty(&st))
	{
		int top = StackTop(&st);
		printf("%d ", top);

		StackPop(&st);
	}
	StackDestroy(&st);
}

int main()
{
	TestStack();
	return 0;
}