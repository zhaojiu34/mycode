#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>

using namespace std;

//移动零
void moveZeroes(vector<int>& nums)
{
    int fast = 0, slow = 0;

    while (fast < nums.size() && slow < nums.size())
    {
        while (slow < nums.size() && nums[slow] != 0)
        {
            slow++;
        }
        while (fast < nums.size() && nums[fast] == 0)
        {
            fast++;
        }

        if (fast < nums.size() && slow < nums.size())
        {
            if (fast > slow)
            {
                int tmp = nums[fast];
                nums[fast] = nums[slow];
                nums[slow] = tmp;
                slow++;
                fast++;
            }
            else
            {
                fast++;
            }
        }
        else
        {
            break;
        }
    }

}

//双指针法
void moveZeroes2(vector<int>& nums)
{
    int dest = -1, cur = 0;
    while (cur < nums.size())
    {
        //1.如果nums[cur] == 0,仅让cur++即可
        if (nums[cur] == 0)
        {
            cur++;
        }
        //2.如果非零，就与dest后一个位置互换，并让dest++，cur++;
        else
        {
            swap(nums[dest + 1], nums[cur]);
            dest++;
            cur++;
        }
    }
}

void moveZeroes2(vector<int>& nums)
{
    for (int dest = -1, cur = 0; cur < nums.size(); cur++)
        if (nums[cur])//处理非零元素
            swap(++dest, cur);
}

int main()
{
    vector<int> v{1,0,1};
    moveZeroes(v);

    return 0;
}