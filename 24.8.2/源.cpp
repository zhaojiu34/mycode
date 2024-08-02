#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string makeGood(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s;

        string ret;

        for (size_t i = 0; i < s.size() - 1;)
        {
            if (s[i] == s[i + 1] + 32 && s[i] == s[i + 1] - 32)
            {
                i += 2;
            }
            else
            {
                ret += s[i];
                i++;
            }
        }

        if (s[s.size() - 2] != s[s.size() - 1] + 32 && s[s.size() - 2] != s[s.size() - 1] - 32)
            ret += s[s.size() - 1];

        return ret;
    }
};

int main()
{

	return 0;
}