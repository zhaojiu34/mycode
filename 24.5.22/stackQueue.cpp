#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include "stackQueue.h"

//��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}
//��ջ
void StackPush(Stack* ps, STDataType x)
{
	//���жϿռ乻����
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			return;
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
	ps->arr[ps->top++] = x;
}
//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);

	assert(!StackEmpty(ps));

	return ps->arr[ps->top - 1];
}
//��ȡջ����ЧԪ�صĸ���
int StacKSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}
//����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}