#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int STDataType;

//ջ�Ľṹ
//�ײ��߼���˳������飩
typedef struct Stack
{
	int* a;
	int top;//ջ��
	int capacity;//����ռ��С
}ST;

//��ʼ��ջ
void StackInit(ST* ps);

//��ջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);

//��ȡջ��Ԫ��
STDataType  StackTop(ST* ps);
//��ȡջ����Ч��Ԫ�ظ���
int StackSize(ST* ps);

//���ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);
//����ջ
void StackDestroy(ST* ps);
