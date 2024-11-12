#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include<string>

using namespace std;

    /**
     * ���ٻ�����
     * @param arr int����vector the array
     * @param aim int���� the target
     * @return int����
     */
int minMoney(vector<int>& arr, int aim) {
    // write code here
    int n = arr.size();
    int dp[aim + 1];  //dp[i]��ʾ��Ҫ�ճ�i���ٵĻ�����
    //memset(dp, 1e9, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= aim; i++) dp[i] = 1e9;
    //һ��ʼdp[i]����ʼ��Ϊ�ܴ��ֵ
    for (int i = 0; i < n; i++)
        for (int j = arr[i]; j <= aim; j++) {
            //һ��ʼ��dp[5]��1e9 ���³���1
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);  //ʹ�����������ÿ�ֻ��ҵ�ֵ
        }

    return dp[aim] == 1e9 ? -1 : dp[aim];
};
