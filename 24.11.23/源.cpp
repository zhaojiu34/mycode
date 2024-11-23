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
        // �Ȱ� stack2 ���� stack1
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }

    int pop() {
        // �Ȱ� stack1 ���� stack2
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