#pragma once
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

typedef int HDataType;

class Heap
{
public:
	//交换
	void Swap(int* px, int* py);

	//向下调整
	void AdjustDown(int parent, int n);

	//向上调整
	void AdjustUp(int child);

	//建立堆
	void Creat(HDataType* a, int n);

	//销毁堆
	void Destroy();

	//向堆中插入数据
	void Push(HDataType x);

	//删除数据
	void Pop();

	//区堆顶的数据
	HDataType top();
	//堆的数据个数
	int Size();

	//堆是否为空
	bool Empty();

private:
	HDataType* _a;
	int _size;
	int _capacity;
};
