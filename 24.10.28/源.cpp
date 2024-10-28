#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


//������ֹ��󣬻ᳬ��int��Χ--->������� 
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> ret;
    //����
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size();)
    {
        for (int j = i + 1; j < nums.size();)
        {

            int left = j + 1, right = nums.size() - 1;

            long long sum = target - (nums[i] + nums[j]);
            //˫ָ�뷨����Ԫ��
            while (left < right)
            {
                if (nums[left] + nums[right] < sum)
                {
                    left++;
                }
                else if (nums[left] + nums[right] > sum)
                {
                    right--;
                }
                else
                {
                    ret.push_back({ nums[i],nums[j],nums[left],nums[right] });

                    left++;
                    right--;

                    //ȥ��+��ֹԽ��
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            //ȥ��
            j++;
            while (j < nums.size() && nums[j - 1] == nums[j]) j++;

        }
        //ȥ��
        i++;
        while (i < nums.size() && nums[i] == nums[i - 1]) i++;
    }

    return ret;
}



int main()
{
    vector<int> v = { -1000000000,-1000000000,1000000000,-1000000000,-1000000000 };
    fourSum(v, 294967296);

    return 0;
}


//int main()
//{
//    int t = 0;
//    cin >> t;
//
//    while (t--)
//    {
//        int n = 0, k = 0;
//        string s;
//        cin >> n >> k;
//        cin >> s;
//
//        int cont = 0;//��õ���
//        for (int i = 0; i < n; i++)
//        {
//            if (s[i] == 'W')
//            {
//                if (i >= 2 && s[i - 1] == 'W' && s[i - 2] == 'W')
//                {
//                    cont += k;
//                }
//                else
//                {
//                    cont++;
//                }
//            }
//            else if (s[i] == 'L')
//            {
//                cont--;
//            }
//        }
//
//        cout << cont << endl;
//    }
//}