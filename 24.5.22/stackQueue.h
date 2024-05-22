#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h> 
typedef int  STDataType;

//����һ��˳���
typedef struct Stack
{
	STDataType* arr;
	int top;//ջ��
	int capacity;//����
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);
//��ջ
void StackPush(Stack* ps, STDataType x);
//��ջ
void StackPop(Stack* ps);

//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
//��ȡջ����ЧԪ�صĸ���
int StacKSize(Stack* ps);
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);
//����ջ
void StackDestroy(Stack* ps);

