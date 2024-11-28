#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        }
        //vector中自带的sort函数进行排序
        sort(input.begin(), input.end());
        //返回排序后的前k小的数
        return vector<int>({ input.begin(),input.begin() + k });
    }
};
