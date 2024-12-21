#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

//斐波那契数列
class Solution {
public:

    int Fibonacci(int n)
    {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 1;
        else
            return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};

//跳台阶
class Solution1 {
public:

    int jumpFloor(int number)
    {
        if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        else
            return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};

//判断是否为回文字符串
bool judge(string str) {
    int left = 0, right = str.size() - 1;
    while (left <= right)
    {
        if (str[left] != str[right])
            return false;

        left++;
        right--;
    }

    return true;
}


//反转字符串
string solve(string str)
{
    string ret;

    if (str.size() == 0)
        return ret;

    auto it = str.rbegin();
    while (it != str.rend())
    {
        ret.push_back(*it);
        it++;
    }

    return ret;

}


string trans(string s, int n)
{
    vector<string> vs;
    int j = 0;
    vs.resize(n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            vs[j].push_back(s[i]);
        }
        else {
            j++;

        }
    }

    string ret;
    auto it = vs.rbegin();
    while (it != vs.rend())
    {
        if (*it != "")
        {
            ret += *it;
            it++;
            if (it != vs.rend())
                ret += ' ';
        }
        else
        {
            it++;
        }
        
    }

    for (size_t i = 0; i < ret.size(); i++)
    {
        if (isalpha(ret[i]))
        {
            if (isupper(ret[i]))
            {
                ret[i] += 32;
            }
            else if (islower(ret[i]))
            {
                ret[i] -= 32;
            }
        }
    }
    int a = 0;

    return ret;
}
int main()
{
    string s("Hello World");
    trans(s,s.size());


	return 0;
}