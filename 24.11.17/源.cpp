#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Transform {
public:
    char trans(char ch) {
        if ('a' <= ch && ch <= 'z') return ch - 'a' + 'A';
        else return ch - 'A' + 'a';
    }
    string trans(string s, int n) {
        int p = n - 1;
        string ans;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                for (int j = i + 1; j <= p; ++j) ans += trans(s[j]);
                ans += ' ';
                p = i - 1;
            }
        }
        for (int j = 0; j <= p; ++j) ans += trans(s[j]);
        return ans;
    }
};