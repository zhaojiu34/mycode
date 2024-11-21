#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param nums int����vector
     * @return int����
     */
    int minNumberDisappeared(vector<int>& nums) {
        int n = nums.size();
        for (auto& x : nums) if (x <= 0) x = n + 1;
        for (auto& x : nums) if (abs(x) <= n) nums[abs(x) - 1] = -1 * abs(nums[abs(x) - 1]);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};




int main()
{
	return 0;
}
