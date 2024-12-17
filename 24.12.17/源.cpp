#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>


using namespace std;

//包含min函数的栈
class Solution2 {
public:
    void push(int value)
    {
        s1.push(value);
    }
    void pop()
    {
        s1.pop();
    }
    int top()
    {
        return s1.top();
    }
    int min()
    {
        stack<int> s(s1);
        int mmin = INT_MAX;

        while (!s.empty())
        {
            int front = s.top();
            if (mmin > front)
                mmin = front;
            s.pop();
        }

        return mmin;
    }

private:
    stack<int> s1;
};

//两个栈实现队列
class Solution1
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int front = 0;

        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                int top = stack1.top();
                stack2.push(top);
                stack1.pop();

            }
        }

        if (stack2.empty())
        {
            front = -1;
        }
        else
        {
            front = stack2.top();
            stack2.pop();
        }

        return front;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};



int main()
{

	return 0;
}