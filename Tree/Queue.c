#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTreeNode.h"
#include "Queue.h"

//��ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}

//����
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

//��β�����
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

//��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	//û��Ԫ��
	if (q->phead == NULL)
		return;

	//ֻ��һ��Ԫ��
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

//��ȡ����ͷ������
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->phead != NULL);

	return q->phead->val;
}

//��ȡ��βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->ptail != NULL);
	return q->ptail->val;
}

//��ȡ�����е���Ч����
int  QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;

}