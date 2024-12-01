#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 左右边为无穷小，所以 当前位 大于临近坐标
    int findPeakElement(vector<int>& nums) {  // 索引logn 二分查找
        int len = nums.size();
        int low = 0, high = len - 1;
        while (low < high) {
            int mid = low + high >> 1;
            nums[mid] < nums[mid + 1] ? low = mid + 1 : high = mid;
        }
        return low;
    }
};
