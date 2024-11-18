#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;


class Solution {
public:
    stack<pair<int, int>> s;
    void push(int value) {
        if (s.empty())
            s.push({ value,value });
        else
            s.push({ value,::min(value,s.top().second) });//思路：每个节点保存当前以及之前进栈的最小值
    }
    void pop() {
        s.pop();
    }
    int top() {
        return s.top().first;
    }
    int min() {
        return s.top().second;
    }
};
