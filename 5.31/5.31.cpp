#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <vector>
#include <string>

//好数对的数目
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int n = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j] && i < j)
                    n++;
            }
        }

        return n;
    }
};

//统计好三元数组
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c)
    {
        int n = 0;
        for (size_t i = 0; i < arr.size(); i++)
        {
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                for (size_t k = j + 1; k < arr.size(); k++)
                {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    {
                        n++;
                    }
                }
            }
        }

        return n;
    }
};

//转换成小写字母
class Solution {
public:
    string toLowerCase(string s)
    {
        for (auto& e : s)
        {
            if (e >= 'A' && e <= 'Z')
                e += 32;
        }

        return s;
    }
};