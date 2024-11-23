#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        // 先把 stack2 推入 stack1
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {
        // 先把 stack1 推入 stack2
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int value = stack2.top();
        stack2.pop();
        return value;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};