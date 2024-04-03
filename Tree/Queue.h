#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "BinaryTreeNode.h"

typedef BTNode*  QDataType;

//����ʽ�ṹ��ʾ����
typedef struct QListNode
{
	struct QListNode* pNext;
	QDataType val;
}QLNode;

//���нṹ
typedef struct Queue
{
	QLNode* phead;
	QLNode* ptail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* q);

//����
void QueueDestroy(Queue* q);

//��β�����
void QueuePush(Queue* q, QDataType x);

//��ͷ������
void QueuePop(Queue* q);

//��ȡ����ͷ������
QDataType QueueFront(Queue* q);

//��ȡ��βԪ��
QDataType QueueBack(Queue* q);

//��ȡ�����е���Ч����
int  QueueSize(Queue* q);

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* q);
