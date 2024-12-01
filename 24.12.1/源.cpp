#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // ���ұ�Ϊ����С������ ��ǰλ �����ٽ�����
    int findPeakElement(vector<int>& nums) {  // ����logn ���ֲ���
        int len = nums.size();
        int low = 0, high = len - 1;
        while (low < high) {
            int mid = low + high >> 1;
            nums[mid] < nums[mid + 1] ? low = mid + 1 : high = mid;
        }
        return low;
    }
};
