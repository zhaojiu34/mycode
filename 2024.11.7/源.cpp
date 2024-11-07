#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include<string>

using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param height int����vector
     * @return int����
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

            //  ÿ�θ�������Ҫ���ڵ���ԭ����ˮƽ
            height[left] < height[right] ? ++left : --right;
        }

        return res;
    }
};
