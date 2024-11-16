#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param cost int����vector
     * @return int����
     */
    int minCostClimbingStairs(vector<int>& cost) {
        // write code here
        if (cost.size() == 1) return cost[0];
        vector<int> dp = { cost[0], cost[1] };
        for (int i = 2; i < cost.size(); i++) {
            dp.push_back(min(dp[i - 1], dp[i - 2]) + cost[i]); // �ӵ�i¥�߻��ѵ���Сֵ
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};


int main()
{

}