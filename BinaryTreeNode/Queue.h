#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Tree.h"

typedef BTNode*  QDataType;

//使用链表表示队列
typedef struct QListNode
{
	struct QListNode* next;
	QDataType x;
}QNode;

//队列结构，两个指针
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;

	int size;//节点个数
}Queue;

//接口

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);
//队尾插入数据
void QueuePush(Queue* pq,QDataType x);
//队顶删除数据
void QueuePop(Queue* pq);
//获取队顶元素
QDataType QueueFront(Queue* pq);
//获取队尾元素
QDataType QueueBack(Queue* pq);
//判断是否为空
bool QueueEmpty(Queue* pq);
//队列元素
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
