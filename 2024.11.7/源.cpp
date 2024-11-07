#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include<string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param height int整型vector
     * @return int整型
     */
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }

        int res = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            int size = (right - left) * std::min(height[left], height[right]);
            res = std::max(res, size);

            //  每次更新下限要大于等于原来的水平
            height[left] < height[right] ? ++left : --right;
        }

        return res;
    }
};
