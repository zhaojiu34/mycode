#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <set>

#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s.size() == 0)
    {
        cout << '0';
        return 0;
    }
    
    //删除相邻的标志
    int flag = 1;

    while (flag != 0)
    {
        int i = 0;

        if (i >= (int)s.size() - 1)
            flag = 0;

        while (i < (int)s.size() - 1)
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }

            i++;
        }
    }
    

    if (s == "")
    {
        cout << '0';
    }

    cout << s;
}


//class Solution {
//public:
//    
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
//    {
//        vector<int> v;
//        set<int> s1(nums1.begin(), nums1.end());
//        set<int>s2(nums2.begin(), nums2.end());
//
//        vector<int> v1(s1.begin(), s1.end());
//        vector<int> v2(s2.begin(), s2.end());
//
//        for (size_t i = 0; i < v1.size(); i++)
//        {
//            for (size_t j = 0; j < v2.size(); j++)
//            {
//                if (v1[i] == v2[j])
//                {
//                    v.push_back(v1[i]);
//                }
//            }
//        }
//
//        return v;
//    }
//};
//
//
//int main()
//{
//    int left = 0, right = 0;
//    cin >> left;
//    cin >> right;
//
//    int cont = 0;
//    for (size_t i = left; i <= right; i++)
//    {
//        if (i == 2)
//        {
//            cont++;
//        }
//        else
//        {
//            size_t n = i;
//            while (n)
//            {
//                if (n % 10 == 2)
//                {
//                    cont++;
//                }
//
//                n /= 10;
//            }
//        }
//    }
//
//    cout << cont;
//}