#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Tree.h"

typedef BTNode*  QDataType;

//ʹ�������ʾ����
typedef struct QListNode
{
	struct QListNode* next;
	QDataType x;
}QNode;

//���нṹ������ָ��
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;

	int size;//�ڵ����
}Queue;

//�ӿ�

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestroy(Queue* pq);
//��β��������
void QueuePush(Queue* pq,QDataType x);
//�Ӷ�ɾ������
void QueuePop(Queue* pq);
//��ȡ�Ӷ�Ԫ��
QDataType QueueFront(Queue* pq);
//��ȡ��βԪ��
QDataType QueueBack(Queue* pq);
//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
//����Ԫ��
int QueueSize(Queue* pq);

//typedef struct
//{
//	Queue q1;
//	Queue q2;
//} MyStack;
//void myStackPush(MyStack* obj, int x);
//int myStackPop(MyStack* obj);
//int myStackTop(MyStack* obj);
//bool myStackEmpty(MyStack* obj);
//void myStackFree(MyStack* obj);
