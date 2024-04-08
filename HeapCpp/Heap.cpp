#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//����
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//���µ���
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

//������
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

//���ٶ�
void Heap::Destroy()
{
	free(_a);
	_a = nullptr;
	_size = 0;
	_capacity = 0;
}

//���ϵ���
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

//����в�������
void Heap::Push(HDataType x) 
{
	//���û�пռ������
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

//ɾ������:ɾ�Ѷ�������
void Heap::Pop()
{

	Swap(&_a[0], &_a[_size - 1]);
	_size--;
	AdjustDown(0, _size);
	
}

//���Ѷ�������
HDataType Heap::top()
{
	return _a[0];

}
//�ѵ����ݸ���
int Heap::Size()
{
	return _size;
}

//���Ƿ�Ϊ��
bool Heap::Empty()
{
	return _size == 0;
}