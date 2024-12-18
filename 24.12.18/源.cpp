#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

    bool sign(int i, stack<char>& chars, string str) {
        if (chars.top() == '(' && str[i] == ')') {
            return true;
        }
        if (chars.top() == '[' && str[i] == ']') {
            return true;
        }
        if (chars.top() == '{' && str[i] == '}') {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        // write code here
        int len = s.length();
        if (len % 2 != 0) {
            return false;
        }
        stack<char> chars;
        for (int i = 0; i < len; i++) {
            if (!chars.empty()) {
                if (sign(i, chars, s)) {
                    chars.pop();
                }
                else {
                    chars.push(s[i]);
                }
            }
            else {
                chars.push(s[i]);
            }
        }
        if (chars.empty()) {
            return true;
        }
        return false;
    }


   


int main()
{


	return 0;
}