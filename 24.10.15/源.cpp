#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <set>

using namespace std;


//最小公倍数
int main() {
    int a, b;
    while (cin >> a >> b)
    {
        int sum = a * b;

        if (a > b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        
        if (b % a == 0)
        {
            cout << a << endl;
        }
        else
        {
            int c = b % a;
            while (c)
            {
                b = a;
                a = c;
                c = b % a;
            }

            cout << sum / a << endl;
        }
        
    }
};

////数组中的最长连续子序列
//int MLS(vector<int>& arr)
//{
//    set<int> s(arr.begin(), arr.end());
//    vector<int> v(s.begin(), s.end());
//
//    int cont = 0;
//    vector<int> num;
//
//    for (size_t i = 0; i < v.size() - 1; i++)
//    {
//        if (v[i] + 1 == v[i + 1])
//        {
//            cont++;
//        }
//        else {
//            num.push_back(cont + 1);
//            cont = 0;
//        }
//    }
//
//    //要看最后一个和前面那一段能不能接起来
//    if (v.size()>=3 && v[v.size() - 1] == v[v.size() - 2] + 1 && v[v.size() - 2] == v[v.size() - 3] + 1)
//    {
//        num[num.size() - 1] += 1;
//    }
//    else
//    {
//        if (v.size() >= 2 && v[v.size() - 1] == v[v.size() - 2] + 1)
//        {
//            num.push_back(2);
//        }
//    }
//
//    int max = 0;
//
//    for (size_t i = 0; i < num.size(); i++)
//    {
//        if (num[i] > max)
//        {
//            max = num[i];
//        }
//    }
//
//    //没有连续的，自身就是最长的连续长度
//    if (max == 0)
//        max += 1;
//
//    return max;
//};
//
//int main()
//{
//    vector<int> a = { 1,1,1,1 };
//    cout << MLS(a);
//
//    return 0;
//}