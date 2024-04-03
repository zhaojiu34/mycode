#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//ջ���Ƚ����

//��ʼ��ջ
void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		//����
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* tmp = (int*)realloc(ps->a,sizeof(int) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top++] = x;

}
//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//��ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top-1];	
}
//��ȡջ����Ч��Ԫ�ظ���
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//���ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}
//����ջ
void StackDestroy(ST* ps)
{
	assert(ps);
	ps->capacity = ps->top = 0;

	free(ps->a);
	ps->a = NULL;
}