#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

//����ö��:����ʱ������
int triangleNumber1(vector<int>& nums)
{
    int cont = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            for (size_t k = 0; k < nums.size(); k++)
            {
                int sum = nums[i] + nums[j];
                int sub = abs(nums[i] - nums[j]);

                if (k != i && k != j && nums[k] < sum && nums[k] > sub)
                {
                    cont++;
                }

            }
        }
    }

    return cont / 3;

}


int triangleNumber(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int c = nums.size() - 1;
    int cont = 0;
    while (c >= 0)
    {
        int left = 0, right = c - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] > nums[c])
            {
                cont += right - left;
                right--;
            }
            else
            {
                left++;
            }
        }
        c--;
    }

    return cont;

}

int triangleNumber(vector<int>& nums)
{
    //1.�Ż�����
    sort(nums.begin(), nums.end());
    int cont = 0;
    int n = nums.size();

    //����˫ָ��������
    for (int i = n - 1; i >= 2; i--)//�̶�������
    {
        //����˫ָ�����ͳ�Ʒ���Ҫ�����Ԫ��ĸ���
        int left = 0, right = i - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] > nums[i])
            {
                cont += right - left;
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    return cont;

}

int main()
{
    vector<int> v = {2,2,3,4 };
    cout << triangleNumber(v);

	return 0;
}