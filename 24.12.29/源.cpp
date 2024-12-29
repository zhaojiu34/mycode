#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define STACK_SIZE 51
using namespace std;
typedef int SElemType;
typedef struct
{
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;
int CreatS(SqStack& S)
{
    S.base = (SElemType*)malloc(STACK_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(-1);
    S.top = S.base;
    S.stacksize = STACK_SIZE;
    return 1;
}
int GetTop(SqStack& S, SElemType& e)
{
    if (S.top == S.base)
        return 0;
    e = *(S.top - 1);
    return 1;
}
int Push(SqStack& S, SElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        //S.base = (SElemType *)realloc(S.base,(S.stacksize+10)*sizeof(SElemType));
        return 0;
    }
    *S.top++ = e;
    return 1;
}
int Pop(SqStack& S, char& e)
{
    if (S.top == S.base)
        return 0;
    e = *--S.top; // e的存在是没有价值的！！记录删除的元素，本题中没有这个操作的必要
    return 1;
}
int Empty(SqStack& S)
{
    if (S.top == S.base)
        return 1;
    else
        return 0;
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string s;
        cin >> s;
        char e;
        int len = s.length();
        SqStack S;
        CreatS(S);
        int f = 1;
        int l = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == 'S')
            {
                Push(S, s[i]);
                l++;
                if (l > m)
                {
                    cout << "NO" << endl;
                    f = 0;
                    break;
                }
            }
            else
            {
                if (Empty(S))
                {
                    cout << "NO" << endl;
                    f = 0;
                    break;
                }
                else
                {
                    Pop(S, e);
                    l--;
                }
            }

        }
        if (f)
        {
            if (Empty(S))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

}