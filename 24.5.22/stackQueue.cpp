#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1
#include "stackQueue.h"

//初始化栈
void StackInit(Stack* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}
//入栈
void StackPush(Stack* ps, STDataType x)
{
	//先判断空间够不够
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
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);

	assert(!StackEmpty(ps));

	return ps->arr[ps->top - 1];
}
//获取栈中有效元素的个数
int StacKSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//检测栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}
//销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}