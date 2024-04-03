#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//void test()
//{
//	
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//
//	while (!QueueEmpty(&q))
//	{
//		printf("%d", QueueFront(&q));
//		QueuePop(&q);
//	}
//	QueueDestroy(&q);
//}
void test()
{
	MyStack* obj = myStackCreate();
	myStackPush(obj, 1);
	myStackPush(obj, 2);
	myStackTop(obj);
	myStackPop(obj);
	myStackPop(obj);
	myStackEmpty(obj);
}
int main()
{
	test();
	return 0;
}