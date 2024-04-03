#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "BinaryTreeNode.h"

typedef BTNode*  QDataType;

//用链式结构表示队列
typedef struct QListNode
{
	struct QListNode* pNext;
	QDataType val;
}QLNode;

//队列结构
typedef struct Queue
{
	QLNode* phead;
	QLNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* q);

//销毁
void QueueDestroy(Queue* q);

//队尾入队列
void QueuePush(Queue* q, QDataType x);

//队头出队列
void QueuePop(Queue* q);

//获取队列头部数据
QDataType QueueFront(Queue* q);

//获取队尾元素
QDataType QueueBack(Queue* q);

//获取队列中的有效个数
int  QueueSize(Queue* q);

//检测队列是否为空
bool QueueEmpty(Queue* q);
