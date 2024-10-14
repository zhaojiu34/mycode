#define _CRT_SECURE_NO_WARNINGS 1

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ans = -1;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        ans = stack2.top();
        stack2.pop();
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};