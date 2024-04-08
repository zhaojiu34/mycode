#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//初始化
void Queue::Init()
{
	_phead = nullptr;
	_ptail = nullptr;
	_size = 0;
}

//销毁
void Queue::Destroy()
{
	QNode* cur = _phead;

	while (cur != nullptr)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}	

	_phead = _ptail = nullptr;
	_size = 0;
}

//队尾入队列
void Queue::Push(QDataType x)
{
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	
	if (tmp == nullptr)
	{
		perror("malloc fail");
		return;
	}

	tmp->_next = nullptr;
	tmp->_val = x;

	if (_ptail == nullptr)
	{
		_phead = _ptail = tmp;
	}
	else
	{
		_ptail->_next = tmp;
		_ptail = _ptail->_next;
	}

	_size++;
}

//队头出数据
void Queue::Pop()
{
	//没有节点
	assert(_ptail != nullptr);

	//只有一个节点
	if (_ptail == _phead)
	{
		_ptail = _phead = nullptr;
	}
	//多个节点
	else
	{
		QNode* cur = _phead->_next;
		free(_phead);
		_phead = cur;
	}

	_size--;
}

//获取队列头部元素
QDataType Queue::Front()
{
	assert(_phead);
	assert(_ptail);

	return _phead->_val;
}

//获取队列尾部元素
QDataType Queue::Back()
{
	assert(_phead);
	assert(_ptail);

	return _ptail->_val;

}

//队列中有效个数
int Queue::Size()
{
	return _size;
}

//队列是否为空
bool Queue::Empty()
{
	return _size == 0;
}