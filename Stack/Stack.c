#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//栈是先进后出

//初始化栈
void StackInit(ST* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		//扩容
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
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

//获取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top-1];	
}
//获取栈中有效的元素个数
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

//检测栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}
//销毁栈
void StackDestroy(ST* ps)
{
	assert(ps);
	ps->capacity = ps->top = 0;

	free(ps->a);
	ps->a = NULL;
}