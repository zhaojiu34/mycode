#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//初始化
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

//销毁
void Stack::Destroy()
{
	free(_a);
	_a = nullptr;
	_top = _capacity = 0;

}

//栈顶入栈
void Stack::Push(SDataType x)
{
	//如果空间不够
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

//栈顶出栈
void Stack::Pop()
{
	assert(_top != 0);

	_top--;
}

//栈是否为空
bool Stack::Empty()
{
	return _top == 0;
}

//栈的有效个数
int Stack::Size()
{

	return _top;
}

//获取栈顶元素
SDataType Stack::Top()
{
	assert(_top != 0);

	return _a[_top - 1];
}