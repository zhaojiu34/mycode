#pragma once

#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;
typedef int QDataType;

class Queue
{
public:
	//初始化
	void Init();

	//销毁
	void Destroy();

	//队尾入队列
	void Push(QDataType x);

	//队头出数据
	void Pop();

	//获取队列头部元素
	QDataType Front();

	//获取队列尾部元素
	QDataType Back();

	//队列中有效个数
	int Size();

	//队列是否为空
	bool Empty();

private:

	typedef struct QListNode
	{
		QDataType _val;//存储的数据
		struct QListNode* _next;//指向下一个节点
	}QNode;

	QNode* _phead;//头指针
	QNode* _ptail;//尾指针
	int _size;//节点个数

};
