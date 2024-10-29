#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minSubArrayLen1(int target, vector<int>& nums)
{
    int n = nums.size();
    int sum = 0;
    int ret = INT_MAX;

    for (int left = 0, right = 0; right < n; right++)
    {
        sum += nums[right];//������

        while (sum >= target)
        {
            ret = min(ret, right - left + 1);//���½��
            sum -= nums[left];//������
            left++;
        }
    }

    return ret == INT_MAX ? 0 : ret;
}


int minSubArrayLen(int target, vector<int>& nums)
{
    int left = 0, right = 0;
    int len = nums.size();
    int sum = 0;
    int ret = 0;

    while (left < len)
    {
        //�ж�
        while (right < len && sum < target)
        {
            //������
            sum += nums[right++];
        }
        
        if (sum >= target)
        {
            //���½��
            if (ret == 0)
                ret = right - left;
            else
                ret = min(ret, right - left);
        }

        //������
        sum -= nums[left];
        left++;
    }

    return ret;

}

int main()
{
    vector<int> v = {8};
    cout << minSubArrayLen(7, v);

    return 0;
}