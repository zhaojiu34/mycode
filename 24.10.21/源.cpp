#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>

using namespace std;

//�ƶ���
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

//˫ָ�뷨
void moveZeroes2(vector<int>& nums)
{
    int dest = -1, cur = 0;
    while (cur < nums.size())
    {
        //1.���nums[cur] == 0,����cur++����
        if (nums[cur] == 0)
        {
            cur++;
        }
        //2.������㣬����dest��һ��λ�û���������dest++��cur++;
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
        if (nums[cur])//�������Ԫ��
            swap(++dest, cur);
}

int main()
{
    vector<int> v{1,0,1};
    moveZeroes(v);

    return 0;
}