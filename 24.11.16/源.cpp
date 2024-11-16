#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param cost int整型vector
     * @return int整型
     */
    int minCostClimbingStairs(vector<int>& cost) {
        // write code here
        if (cost.size() == 1) return cost[0];
        vector<int> dp = { cost[0], cost[1] };
        for (int i = 2; i < cost.size(); i++) {
            dp.push_back(min(dp[i - 1], dp[i - 2]) + cost[i]); // 从第i楼走花费的最小值
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};


int main()
{

}