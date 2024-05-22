#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h> 
typedef int  STDataType;

//定义一个顺序表
typedef struct Stack
{
	STDataType* arr;
	int top;//栈顶
	int capacity;//容量
}Stack;

//初始化栈
void StackInit(Stack* ps);
//入栈
void StackPush(Stack* ps, STDataType x);
//出栈
void StackPop(Stack* ps);

//获取栈顶元素
STDataType StackTop(Stack* ps);
//获取栈中有效元素的个数
int StacKSize(Stack* ps);
//检测栈是否为空
bool StackEmpty(Stack* ps);
//销毁栈
void StackDestroy(Stack* ps);

