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
     * @param nums int整型vector
     * @return int整型
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