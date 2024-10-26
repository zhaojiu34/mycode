#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> vv;

    //1.����
    sort(nums.begin(), nums.end());

    //2.˫ָ��������
    for (int i = 0; i < nums.size();)
    {
        //С�Ż������nums[i]>0,֮���������ֵ��Ӳ�����Ϊ����
        if (nums[i] > 0)
            break;

        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int target = -nums[i];//�̶�һ������ȡ�����෴��
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

                //ȥ�أ�left��right����ֹԽ��
                while (left < right && nums[left - 1] == nums[left])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
        }

        //ȥ�أ�left��right����ֹԽ��
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

//����֮�ͣ����������ظ�Ԫ��ȥ��
vector<vector<int>> threeSum1(vector<int>& nums)
{
    vector<vector<int>> vv;
    //����
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        //ʹ����һ��˫ָ���Ժ�i�����ظ�Ԫ��
        if (i != 0 && nums[i] == nums[i - 1] && i < nums.size())
        {
            continue;
        }
        else if (i >= nums.size())
        {
            break;
        }

        //����˫ָ�룬�ȹ̶�һ����
        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            //�����ظ�Ԫ�أ�����ֹԽ��
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




//����֮��:��������setȥ��
vector<vector<int>> threeSum2(vector<int>& nums)
{
    vector<vector<int>> ret;

    //�Ż���������֮�����õ�����
    sort(nums.begin(), nums.end());

    int n = nums.size();
    //˫ָ���Һ�Ϊ0����Ԫ����
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

    //ȥ��
    set<vector<int>> s(ret.begin(), ret.end());

    vector<vector<int>> vv(s.begin(), s.end());

    return vv;
}