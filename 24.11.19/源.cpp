#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<vector>
#include <string>

using namespace std;

class Solution {
public:
    int editDistance(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1, 0)); //dp[i][j]表示到str1[i]和str2[j]为止的子串需要的编辑距离
        for (int i = 1; i <= n1; i++) //初始化边界
            dp[i][0] = dp[i - 1][0] + 1;
        for (int i = 1; i <= n2; i++)
            dp[0][i] = dp[0][i - 1] + 1;
        for (int i = 1; i <= n1; i++) //遍历第一个字符串的每个位置
            for (int j = 1; j <= n2; j++) { //对应第二个字符串每个位置
                if (str1[i - 1] == str2[j - 1]) //若是字符相同，此处不用编辑
                    dp[i][j] = dp[i - 1][j - 1]; //直接等于二者前一个的距离
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; //选取最小的距离加上此处编辑距离1
            }
        return dp[n1][n2];
    }
};
