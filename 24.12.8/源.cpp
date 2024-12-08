#define _CRT_SECURE_NO_WARNINGS 1

#include<iosream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        // write code here
        stack<char> sign;
        stack<int> num;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int rear = i;
                while ((rear + 1) < s.length() && s[rear + 1] >= '0' && s[rear + 1] <= '9') {
                    rear++;
                }
                int n = 0;
                for (int j = rear; j >= i; j--) {
                    n += (s[j] - '0') * pow(10, (rear - j));
                }
                i = rear;
                num.push(n);
            }
            else if (sign.size() == 0 || s[i] == '*' || s[i] == '(') {
                sign.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-') {
                while (1) {
                    if (sign.size() == 0) {
                        break;
                    }
                    if (sign.top() == '*') {
                        sign.pop();
                        int n2 = num.top();
                        num.pop();
                        int n1 = num.top();
                        num.pop();
                        num.push(n1 * n2);
                    }
                    else if (sign.top() == '+') {
                        sign.pop();
                        int n2 = num.top();
                        num.pop();
                        int n1 = num.top();
                        num.pop();
                        num.push(n1 + n2);
                    }
                    else if (sign.top() == '-') {
                        sign.pop();
                        int n2 = num.top();
                        num.pop();
                        int n1 = num.top();
                        num.pop();
                        num.push(n1 - n2);
                    }
                    else {
                        break;
                    }
                }
                sign.push(s[i]);
            }
            else if (s[i] == ')') {
                while (1) {
                    if (sign.size() == 0) {
                        break;
                    }
                    else if (sign.top() == '(') {
                        sign.pop();
                        break;
                    }
                    else if (sign.top() == '+') {
                        sign.pop();
                        int n2 = num.top();
                        num.pop();
                        int n1 = num.top();
                        num.pop();
                        num.push(n1 + n2);
                    }
                    else if (sign.top() == '-') {
                        sign.pop();
                        int n2 = num.top();
                        num.pop();
                        int n1 = num.top();
                        num.pop();
                        num.push(n1 - n2);
                    }
                    else if (sign.top() == '*') {
                        sign.pop();
                        int n2 = num.top();
                        num.pop();
                        int n1 = num.top();
                        num.pop();
                        num.push(n1 * n2);
                    }
                }
            }
        }
        while (sign.size() != 0) {
            if (sign.top() == '+') {
                sign.pop();
                int n2 = num.top();
                num.pop();
                int n1 = num.top();
                num.pop();
                num.push(n1 + n2);
            }
            else if (sign.top() == '-') {
                sign.pop();
                int n2 = num.top();
                num.pop();
                int n1 = num.top();
                num.pop();
                num.push(n1 - n2);
            }
            else if (sign.top() == '*') {
                sign.pop();
                int n2 = num.top();
                num.pop();
                int n1 = num.top();
                num.pop();
                num.push(n1 * n2);
            }
        }
        return num.top();
    }
};