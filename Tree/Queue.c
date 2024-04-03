#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTreeNode.h"
#include "Queue.h"

//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}

//销毁
void QueueDestroy(Queue* q)
{
	assert(q);
	QLNode* cur = q->phead;

	while (cur)
	{
		QLNode* next = cur->pNext;
		free(cur);
		cur = next;
	}

	q->phead = q->ptail = NULL;
	q->size = 0;
}

//队尾入队列
void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QLNode* tmp = (QLNode*)malloc(sizeof(QLNode));
	if (tmp == NULL)
	{
		perror("QueuePush:malloc fail");
		return;
	}
	tmp->val = x;
	tmp->pNext = NULL;
	if (q->phead == NULL)
	{
		q->phead = q->ptail = tmp;
	}
	else
	{
		q->ptail->pNext = tmp;
		q->ptail = tmp;
	}
	q->size++;
}

//队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	//没有元素
	if (q->phead == NULL)
		return;

	//只有一个元素
	if (q->phead->pNext == NULL)
	{
		free(q->phead);
		q->phead = q->ptail = NULL;
	}
	else
	{
		QLNode* del = q->phead;
		q->phead = q->phead->pNext;
		free(del);
		del = NULL;
	}
	q->size--;
}

//获取队列头部数据
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->phead != NULL);

	return q->phead->val;
}

//获取队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->ptail != NULL);
	return q->ptail->val;
}

//获取队列中的有效个数
int  QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

//检测队列是否为空
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;

}