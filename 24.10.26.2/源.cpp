#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> vv;

    //1.排序
    sort(nums.begin(), nums.end());

    //2.双指针解决问题
    for (int i = 0; i < nums.size();)
    {
        //小优化：如果nums[i]>0,之后区间的两值相加不可能为负数
        if (nums[i] > 0)
            break;

        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int target = -nums[i];//固定一个数，取它的相反数
            int sum = nums[left] + nums[right];

            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
            {
                vv.push_back({ nums[left],nums[i],nums[right] });
                left++;
                right--;

                //去重，left和right，防止越界
                while (left < right && nums[left - 1] == nums[left])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
        }

        //去重，left和right，防止越界
        i++;
        while (i < nums.size() && nums[i] == nums[i - 1]) i++;
    }

    return vv;
}

int main()
{
    vector<int> v = { -1,0,1,2,-1,-4 };

    threeSum(v);

    return 0;
}

//三数之和：利用跳过重复元素去重
vector<vector<int>> threeSum1(vector<int>& nums)
{
    vector<vector<int>> vv;
    //排序
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        //使用完一次双指针以后，i跳过重复元素
        if (i != 0 && nums[i] == nums[i - 1] && i < nums.size())
        {
            continue;
        }
        else if (i >= nums.size())
        {
            break;
        }

        //利用双指针，先固定一个数
        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            //跳过重复元素，并防止越界
            if (left != i + 1 && nums[left - 1] == nums[left] && left < nums.size())
            {
                left++;
                continue;
            }
            else if (left >= nums.size())
            {
                break;
            }

            if (right != nums.size() - 1 && nums[right + 1] == nums[right] && right > left)
            {
                right--;
                continue;
            }
            else if (right <= left)
            {
                break;
            }

            if (nums[left] + nums[right] == 0 - nums[i])
            {
                vv.push_back({ nums[left] ,nums[right],nums[i] });
                left++;
                right--;
            }
            else if (nums[left] + nums[right] < 0 - nums[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return vv;
}




//三数之和:利用容器set去重
vector<vector<int>> threeSum2(vector<int>& nums)
{
    vector<vector<int>> ret;

    //优化：先排序，之后利用单调性
    sort(nums.begin(), nums.end());

    int n = nums.size();
    //双指针找和为0的三元数组
    for (int i = n - 1; i >= 2; i--)
    {
        int left = 0, right = i - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] + nums[i] == 0)
            {
                ret.push_back({ nums[left],nums[right],nums[i] });
                left++;
                right--;
            }
            else if (nums[left] + nums[right] + nums[i] > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    //去重
    set<vector<int>> s(ret.begin(), ret.end());

    vector<vector<int>> vv(s.begin(), s.end());

    return vv;
}