#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

//查找总价格为目标值的两件商品---双指针法
vector<int> twoSum(vector<int>& price, int target)
{
    vector<int> ret;
    int left = 0, right = price.size() - 1;
    while (left < right)
    {
        if (price[left] + price[right] > target)
        {
            right--;
        }
        else if (price[left] + price[right] < target)
        {
            left++;
        }
        else
        {
            ret.push_back(price[left]);
            ret.push_back(price[right]);
            break;
        }
    }

    return ret;
}