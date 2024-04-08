#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//��ʼ��
void Stack::Init(int n)
{
	_a = (SDataType*)malloc(sizeof(SDataType) * n);

	if (_a == nullptr)
	{
		perror("malloc fail");
		return;
	}

	_top = 0;
	_capacity = n;
}

//����
void Stack::Destroy()
{
	free(_a);
	_a = nullptr;
	_top = _capacity = 0;

}

//ջ����ջ
void Stack::Push(SDataType x)
{
	//����ռ䲻��
	if (_top == _capacity)
	{
		int newCapacity = _capacity * 2;
		SDataType* tmp = (SDataType*)realloc(_a, sizeof(SDataType) * newCapacity);

		if (tmp == nullptr)
		{
			perror("realloc fail");
			return;
		}

		_a = tmp;
		_capacity = newCapacity;
	}

	_a[_top++] = x;
}

//ջ����ջ
void Stack::Pop()
{
	assert(_top != 0);

	_top--;
}

//ջ�Ƿ�Ϊ��
bool Stack::Empty()
{
	return _top == 0;
}

//ջ����Ч����
int Stack::Size()
{

	return _top;
}

//��ȡջ��Ԫ��
SDataType Stack::Top()
{
	assert(_top != 0);

	return _a[_top - 1];
}