#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <cmath>
#include<vector>

using namespace std;

//bool boolnum(size_t n)
//{
//    if (n == 0 || n == 1)
//        return false;
//
//    for (size_t i = 2; i <= (int)sqrt(n); i++)
//    {
//        if (n % i == 0)
//            return false;
//    }
//
//    return true;
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int cont = 0;
//    for (size_t i = 0; i < n; i++)
//    {
//        if (boolnum(i))
//        {
//            cont++;
//        }
//    }
//
//    cout << cont;
//}
//// 64 Î»Êä³öÇëÓÃ printf("%lld")
//
//
//int FirstNotRepeatingChar(string str)
//{
//    vector<char> v;
//    v.resize(52);
//    for (const auto& e : str)
//    {
//        v[e - 'A']++;
//    }
//
//    for (size_t i = 0; i < str.size(); i++)
//    {
//        if (v[str[i] - 'A'] == 1)
//            return i;
//    }
//
//    return -1;
//}

class Solution {
public:
    bool isUnique(string astr)
    {
        vector<char> v;
        v.resize(26, 0);

        for (size_t i = 0; i < astr.size(); i++)
        {
            v[astr[i] - 'a']++;

            if (v[astr[i] - 'a'] > 1)
                return false;
        }

        return true;

    }
};

int main()
{
    string s = "iluhwpyk";
   Solution().isUnique(s);


    return 0;
}