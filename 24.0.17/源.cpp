#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include<vector>
#include <cmath>
using namespace std;

//int main()
//{
//    vector<int> v;
//    int n = 0;
//    cin >> n;
//
//    vector<int> price;
//    price.resize(n);
//    for (size_t i = 0; i < n; i++)
//    {
//        cin >> price[i];
//    }
//
//    for (size_t i = 0; i < n; i++)
//    {
//        for (size_t j = i + 1; j < n; j++)
//        {
//            if(price[j] - price[i] >= 0)
//                v.push_back(price[j] - price[i]);
//        }
//    }
//
//    if (v.size() == 0)
//    {
//        cout << 0;
//        return 0;
//    }
//
//    int min = v[0];
//    for (size_t i = 0; i < v.size(); i++)
//    {
//        if (min < v[i])
//        {
//            min = v[i];
//        }
//    }
//
//    cout << min;
//
//    return 0;
//}


int getLongestPalindrome(string A)
{
    if (A.size() == 1)
        return 1;

    int right = A.size() - 1, left = 0;
    int cont = 0;
    while (left <= right)
    {
        if (A[left] == A[right])
        {
            cont += 2;
            right--;
            left++;
        }
        else
        {
            cont = 0;
            right--;
        }
    }

    if (left != right)
    {
        cont--;
    }

    return cont;
}

int main()
{

    string s = "abbba";

   cout << getLongestPalindrome(s);

    return 0;
}