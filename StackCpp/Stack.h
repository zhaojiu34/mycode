#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

using namespace std;

typedef int SDataType;

class Stack
{
public:
	//��ʼ��
	void Init(int n = 4);

	//����
	void Destroy();

	//ջ����ջ
	void Push(SDataType x);

	//ջ����ջ
	void Pop();

	//ջ�Ƿ�Ϊ��
	bool Empty();

	//ջ����Ч����
	int Size();

	//��ȡջ��Ԫ��
	SDataType Top();

private:
	SDataType* _a;
	int _top;
	int _capacity;
};
