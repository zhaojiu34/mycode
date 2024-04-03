#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//����
void QueueDestroy(Queue* pq)
{
	QNode* cur = pq->phead;
	pq->size = 0;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
}
//��β��������
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
//�Ӷ�ɾ������
void QueuePop(Queue* pq)
{
	assert(pq);
	//�޽ڵ�
	assert(pq->phead);
	//һ���ڵ�
	if (pq->phead->next == NULL)
	{
		pq->phead = pq->ptail = NULL;
	}
	//����ڵ�
	else
	{
		QNode* cur = pq->phead->next;
		free(pq->phead);
		pq->phead = cur;
	}
	pq->size--;
}
//��ȡ�Ӷ�Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq->phead != NULL);
	assert(pq);
	return pq->phead->x;
}
//��ȡ��βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq->ptail != NULL);
	assert(pq);
	return pq->ptail->x;
}
//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}
//����Ԫ��
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}



MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	//�ȼ������һ��Ϊ�գ����ж�Ϊ��
	Queue* pNonEmpty = &obj->q2;
	Queue* pEmpty = &obj->q1;
	if (!QueueEmpty(&obj->q1))
	{
		Queue* pNonEmpty = &obj->q1;
		Queue* pEmpty = &obj->q2;
	}
	//�Ѳ�Ϊ�ն��е�ǰn-1�����ڿյĶ�����
	while (QueueSize(pNonEmpty) > 1)
	{
		int front = QueueFront(pNonEmpty);
		QueuePush(pEmpty, front);
		QueuePop(pNonEmpty);
	}
	int front = QueueFront(pNonEmpty);
	QueuePop(pNonEmpty);
	return front;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}
