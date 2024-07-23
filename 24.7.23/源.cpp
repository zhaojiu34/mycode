#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string compressString(string S)
    {
        int len1 = S.size();
        string s;

        for (size_t i = 0; i < len1; )
        {
            int cont = 0;

            for (size_t j = i; j < len1; j++)
            {
                if (S[i] == S[j])
                {
                    cont++;
                }
                else
                {
                    break;
                }

            }

            s += S[i];
            i += cont;
            if (cont < 10)
                s += cont + '0';
            else {
                s += to_string(cont);
            }

        }

        int len2 = s.size();
        if (len1 <= len2)
            return S;

        return s;

    }
};