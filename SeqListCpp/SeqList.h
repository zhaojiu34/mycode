#pragma once
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

typedef int SDataType;

class SqeList
{
public:
	//初始化
	void Init(int n = 4);
	//销毁
	void Destroy();
	//打印
	void Print();
	//扩容
	void CheckCapacity();

	//头部的插入删除 尾部的插入和删除
	void PushBack(SDataType x);
	void PopBack();
	void PushFront(SDataType x);
	void PopFront();

	//指定位置插入删除
	void Insert(int pos, SDataType x);
	void Erase(int pos);

	//查找
	int Find(SDataType x);

private:
	SDataType* _a;
	int _capacity;
	int _size;
};