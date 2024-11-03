#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size() + 1];
        for (int i = 0; i <= nums.size(); i++)dp[i] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        return dp[nums.size()];
    }
};