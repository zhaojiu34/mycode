#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        vector<int> sum;
        int len = nums.size();

        sum.resize(len);

        for (size_t j = 0; j < nums.size(); j++)
        {
            if (j == 0)
                sum[j] = nums[j];
            else
            {
                sum[j] = sum[j - 1] + nums[j];
            }

        }

        return sum;

    }
};