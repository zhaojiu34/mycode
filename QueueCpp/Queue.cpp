#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//��ʼ��
void Queue::Init()
{
	_phead = nullptr;
	_ptail = nullptr;
	_size = 0;
}

//����
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

//��β�����
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

//��ͷ������
void Queue::Pop()
{
	//û�нڵ�
	assert(_ptail != nullptr);

	//ֻ��һ���ڵ�
	if (_ptail == _phead)
	{
		_ptail = _phead = nullptr;
	}
	//����ڵ�
	else
	{
		QNode* cur = _phead->_next;
		free(_phead);
		_phead = cur;
	}

	_size--;
}

//��ȡ����ͷ��Ԫ��
QDataType Queue::Front()
{
	assert(_phead);
	assert(_ptail);

	return _phead->_val;
}

//��ȡ����β��Ԫ��
QDataType Queue::Back()
{
	assert(_phead);
	assert(_ptail);

	return _ptail->_val;

}

//��������Ч����
int Queue::Size()
{
	return _size;
}

//�����Ƿ�Ϊ��
bool Queue::Empty()
{
	return _size == 0;
}