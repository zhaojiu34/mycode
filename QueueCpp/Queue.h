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
	//��ʼ��
	void Init();

	//����
	void Destroy();

	//��β�����
	void Push(QDataType x);

	//��ͷ������
	void Pop();

	//��ȡ����ͷ��Ԫ��
	QDataType Front();

	//��ȡ����β��Ԫ��
	QDataType Back();

	//��������Ч����
	int Size();

	//�����Ƿ�Ϊ��
	bool Empty();

private:

	typedef struct QListNode
	{
		QDataType _val;//�洢������
		struct QListNode* _next;//ָ����һ���ڵ�
	}QNode;

	QNode* _phead;//ͷָ��
	QNode* _ptail;//βָ��
	int _size;//�ڵ����

};
