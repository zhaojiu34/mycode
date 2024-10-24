#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//暴力枚举：超出时间复杂度
class Solution1 {
public:
    int maxArea(vector<int>& height)
    {
        vector<int> s;

        for (size_t i = 0; i < height.size(); i++)
        {
            for (size_t j = 0; j < height.size(); j++)
            {
                int len = i - j;
                int wid = (height[i] > height[j]) ? height[j] : height[i];
                s.push_back(abs(len) * wid);
            }
        }

        int maxs = s[0];
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] > maxs)
                maxs = s[i];
        }

        return maxs;
    }
};

//双指针
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int max = 0;
        int left = 0, right = height.size() - 1;

        while (left <= right)
        {
            int v = (height[left] > height[right] ? height[right] : height[left]) * (right - left);

            if (max < v)
                max = v;

            if (height[left] > height[right])
                right--;
            else
                left++;
        }

        return max;
    }
};

//最优版本
int maxArea(vector<int>& height)
{
    int ret = 0;
    int left = 0, right = height.size() - 1;

    while (left <= right)
    {
        int v = min(height[left], height[right]) * (right - left);
        ret = max(ret, v);

        //移动指针，谁小移动谁
        if (height[left] > height[right]) right--;
        else left++;
    }

    return ret;
}
int main()
{

	return 0;
}