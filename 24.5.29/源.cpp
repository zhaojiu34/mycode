#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>


class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        int* cout = new int[len * 2]{ 0 };

        int min = INT_MAX;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] < min)
                min = nums[i];
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            cout[nums[i] - min]++;
        }

        int n = 0;
        for (size_t i = 0; i < len * 2; i++)
        {
            if (cout[i] != 0)
            {
                nums[n] = i + min;
                n++;
            }

        }

        sort(nums.begin(), nums.begin() + n);

        return n;

    }
};


class solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int val = 0;
        for (int x : nums)
        {
            val ^= x;
        }
        return val;

    }
};
