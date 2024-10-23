#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include <vector>
#include <string>

class Solution {
public:
    /**
     *
     * @param n intÕûÐÍ
     * @return string×Ö·û´®vector
     */
    void dfs(string s, int left, int n, vector<string>& ans) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (left < n) {
            dfs(s + "(", left + 1, n, ans);
        }
        if (left && left * 2 > s.size()) {
            dfs(s + ")", left, n, ans);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        // write code here
        vector<string> ans;
        dfs("(", 1, n, ans);
        return ans;
    }
};
