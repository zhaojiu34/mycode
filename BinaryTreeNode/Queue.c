#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	pq->size = 0;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->ptail = NULL;
}
//队尾插入数据
void QueuePush(Queue* pq, QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));

	if (newnode == NULL)
	{
		perror("malloc fail!");
		return;
	}
	newnode->next = NULL;
	newnode->x = x;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
//队顶删除数据
void QueuePop(Queue* pq)
{
	assert(pq);
	//无节点
	assert(pq->phead);
	//一个节点
	if (pq->phead->next == NULL)
	{
		pq->phead = pq->ptail = NULL;
	}
	//多个节点
	else
	{
		QNode* cur = pq->phead->next;
		free(pq->phead);
		pq->phead = cur;
	}
	pq->size--;
}

//获取队顶元素
QDataType QueueFront(Queue* pq)
{
	assert(pq->phead != NULL);
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->phead->x;
}
//获取队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq->ptail != NULL);
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->ptail->x;
}
//判断是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}
//队列元素
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}



//MyStack* myStackCreate() {
//	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//	
//
//	QueueInit(&pst->q1);
//
//	QueueInit(&pst->q2);
//	return pst;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	if (!QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	//先假设队列一不为空，队列二为空
//	Queue* pNonEmpty = &obj->q2;
//	Queue* pEmpty = &obj->q1;
//	if (!QueueEmpty(&obj->q1))
//	{
//		Queue* pNonEmpty = &obj->q1;
//		Queue* pEmpty = &obj->q2;
//	}
//	//把不为空队列的前n-1个放在空的队列中
//	while (QueueSize(pNonEmpty) > 1)
//	{
//		int front = QueueFront(pNonEmpty);
//		QueuePush(pEmpty, front);
//		QueuePop(pNonEmpty);
//	}
//	int front = QueueFront(pNonEmpty);
//	QueuePop(pNonEmpty);
//	return front;
//}
//
//int myStackTop(MyStack* obj) {
//	if (!QueueEmpty(&obj->q1))
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//	free(obj);
//}
