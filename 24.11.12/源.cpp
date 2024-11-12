#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include<string>

using namespace std;

    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
int minMoney(vector<int>& arr, int aim) {
    // write code here
    int n = arr.size();
    int dp[aim + 1];  //dp[i]表示需要凑成i最少的货币数
    //memset(dp, 1e9, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= aim; i++) dp[i] = 1e9;
    //一开始dp[i]都初始化为很大的值
    for (int i = 0; i < n; i++)
        for (int j = arr[i]; j <= aim; j++) {
            //一开始的dp[5]由1e9 更新成了1
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);  //使用这个来更新每种货币的值
        }

    return dp[aim] == 1e9 ? -1 : dp[aim];
};
