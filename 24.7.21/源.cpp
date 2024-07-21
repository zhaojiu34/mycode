#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <map>



using namespace std;


class Solution {
public:
    bool CheckPermutation(string s1, string s2)
    {
        vector<char> v1;
        vector<char> v2;
        v1.resize(26, 0);
        v2.resize(26, 0);
        for (const auto& e : s1)
        {
            v1[e - 'a']++;
        }
        for (const auto& e : s2)
        {
            v2[e - 'a']++;
        }

        for (size_t i = 0; i < 26; i++)
        {
            if (v1[i] != v2[i])
                return false;
        }

        return true;


    }
};


class Solution {
public:
    bool canPermutePalindrome(string s)
    {
        map<char, int> m;

        for (const auto& e : s)
        {
            auto ret = m.find(e);

            if (ret == m.end())
            {
                m.insert({ e,1 });
            }
            else
            {
                ret->second++;
            }
        }

        int len = s.size();
        int flag = 0;
        for (const auto& e : m)
        {
            if (e.second % 2 != 0)
            {
                flag++;
            }
        }


        if (len % 2 == 0)
        {
            if (flag != 0)
            {
                return false;
            }
        }
        else
        {
            if (flag != 1)
            {
                return false;
            }
        }

        return true;
    }
};