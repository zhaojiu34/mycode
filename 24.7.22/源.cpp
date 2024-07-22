#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
    int n = 0;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        int len = s.size();
        if (len >= 10)
        {
            cout << s[0] << len - 2 << s[len - 1] << endl;
        }
        else {
            cout << s << endl;
        }
    }
}

class Solution {
public:
    string replaceSpaces(string S, int length)
    {
        string s;

        for (size_t i = 0; i < length; i++)
        {
            if (S[i] != ' ')
            {
                s += S[i];
            }
            else
            {
                s += "%20";
            }
        }

        return s;

    }
};