#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;




int main()
{
    int n = 0;
    cin >> n;

    vector<int> v;
    for (size_t i = 0; i < 3 * n; i++)
    {
        int num = 0;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    vector<vector<int>> vv;
    vv.resize(3);

    int i = 0, j = 0;
    while (i < v.size())
    {
        int num = n;
        while (num--)
        {
            vv[j].push_back(v[i]);
            i++;
        }

        j++;
    }

    int ret = 0;
    for (int k = 0; k < vv[1].size(); k++)
    {
        ret += vv[1][k];
    }

    cout << ret << endl;
}





//Æ¹ÅÒÇò¿ò
//int main()
//{
//    string s1;
//    string s2;
//
//    cin >> s1 >> s2;
//
//    sort(s1.begin(), s1.end());
//    sort(s2.begin(), s2.end());
//
//    int l1 = 0, l2 = 0;
//    while (l1 < s1.size() && l2 < s2.size())
//    {
//        if (s1[l1] == s2[l2])
//        {
//            l1++;
//            l2++;
//        }
//
//        if (s1[l1] != s2[l2])
//        {
//            l1++;
//        }
//    }
//
//    if (l2 == s2.size() && l1 <= s1.size())
//        cout << "Yes" << endl;
//    else
//        cout << "No" << endl;
//
//}