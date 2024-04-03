#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int STDataType;

//栈的结构
//底层逻辑是顺序表（数组）
typedef struct Stack
{
	int* a;
	int top;//栈顶
	int capacity;//数组空间大小
}ST;

//初始化栈
void StackInit(ST* ps);

//入栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);

//获取栈顶元素
STDataType  StackTop(ST* ps);
//获取栈中有效的元素个数
int StackSize(ST* ps);

//检测栈是否为空
bool StackEmpty(ST* ps);
//销毁栈
void StackDestroy(ST* ps);
