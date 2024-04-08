#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//交换
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//向下调整
void Heap::AdjustDown(int parent, int n)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && _a[child] > _a[child])
			child++;

		if (_a[child] > _a[parent])
		{
			Swap(&_a[child], &_a[parent]);
			parent = child;
			child = parent *2 + 1;
		}
		else
		{
			break;
		}
	}
}

//建立堆
void Heap::Creat(HDataType* a, int n)
{
	HDataType* tmp = (HDataType*)malloc(sizeof(HDataType) * n);

	if (tmp == nullptr)
	{
		perror("malloc fail");
		return;
	}
	_a = tmp;

	memcpy(_a, a, sizeof(HDataType) * n);

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(i ,n);
	}

	_size = n;
	_capacity = n;
}

//销毁堆
void Heap::Destroy()
{
	free(_a);
	_a = nullptr;
	_size = 0;
	_capacity = 0;
}

//向上调整
void Heap::AdjustUp(int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (_a[child] > _a[parent])
		{
			Swap(&_a[child], &_a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;

	}

}

//向堆中插入数据
void Heap::Push(HDataType x) 
{
	//如果没有空间就扩容
	if (_size == _capacity)
	{
		int newCapacity = _capacity * 2;
		HDataType* tmp = (HDataType*)realloc(_a, sizeof(HDataType) * newCapacity);

		if (tmp == nullptr)
		{
			perror("realloc fail");
			return;
		}

		_a = tmp;
		_capacity = newCapacity;
	}

	_a[_size++] = x;

	AdjustUp(_size-1);
}

//删除数据:删堆顶的数据
void Heap::Pop()
{

	Swap(&_a[0], &_a[_size - 1]);
	_size--;
	AdjustDown(0, _size);
	
}

//区堆顶的数据
HDataType Heap::top()
{
	return _a[0];

}
//堆的数据个数
int Heap::Size()
{
	return _size;
}

//堆是否为空
bool Heap::Empty()
{
	return _size == 0;
}