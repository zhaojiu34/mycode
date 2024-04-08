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
	//初始化
	void Init(int n = 4);

	//销毁
	void Destroy();

	//栈顶入栈
	void Push(SDataType x);

	//栈顶出栈
	void Pop();

	//栈是否为空
	bool Empty();

	//栈的有效个数
	int Size();

	//获取栈顶元素
	SDataType Top();

private:
	SDataType* _a;
	int _top;
	int _capacity;
};
