#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void recursion(int left, int right, string temp, vector<string>& res, int n) {
        if (left == n && right == n) { //左右括号都用完了，就加入结果
            res.push_back(temp);
            return;
        }
        if (left < n) //使用一次左括号
            recursion(left + 1, right, temp + "(", res, n);
        if (right < n && left > right) //使用右括号个数必须少于左括号
            recursion(left, right + 1, temp + ")", res, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res; //记录结果
        string temp; //记录每次组装的字符串
        recursion(0, 0, temp, res, n); //递归
        return res;
    }
};
