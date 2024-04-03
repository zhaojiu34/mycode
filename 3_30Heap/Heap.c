#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
//排大堆

//交换
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

//向下调整
void AdjustDown(HDataType* a, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
//堆的构建
void HeapCreat(Heap* hp, HDataType* a, int n)
{
	assert(hp);

	int* tmp = (int*)malloc(sizeof(HDataType) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	hp->a = tmp;

	memcpy(hp->a ,a,sizeof(HDataType) * n);
	hp->capacity = hp->size = n;

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, i, n);
	}

}
//堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	hp->capacity  = hp->size= 0;

	free(hp->a);
	hp->a = NULL;
}

//向上调整
void AdjustUp(HDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child >= 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}
//堆的插入
void HeapInsert(Heap* hp,HDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		//扩容
		int newcapacity = hp->capacity * 2;
		int* tmp = (int*)realloc(hp->a, sizeof(int) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}

		hp->a = tmp;
		hp->capacity = newcapacity;
	}

	hp->a[hp->size++] = x;
	//向上调整
	AdjustUp(hp->a, hp->size - 1);

}
//堆的删除，删除堆顶数据
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a, 0, hp->size);

}

//取堆顶数据
HDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	return hp->a[0];
}

//堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}
//堆是否为空
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}