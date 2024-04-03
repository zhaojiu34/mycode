#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>


///堆结构
//底层逻辑也是数组
typedef int HDataType;

typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
}Heap;


//向下调整
void AdjustDown(HDataType* a, int parent, int n);
//向上调整
void AdjustUp(HDataType* a, int child);

//堆的构建
void HeapCreat(Heap* hp, HDataType* a, int n);
//堆的销毁
void HeapDestroy(Heap* hp);

//堆的插入
void HeapInsert(Heap* hp, HDataType x);
//堆的删除，删除堆顶数据
void HeapPop(Heap* hp);

//取堆顶数据
HDataType HeapTop(Heap* hp);
//堆的数据个数
int HeapSize(Heap* hp);
//堆是否为空
bool HeapEmpty(Heap* hp);

