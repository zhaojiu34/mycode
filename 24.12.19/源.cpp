#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

//有效括号序列
bool isValid(string s)
{
    int len = s.size();

    if (len == 1 || len == 0)
        return false;

    stack<char> ss;
    int i = 0;
    while (i < len)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            ss.push(s[i++]);

        else
        {
            if (ss.empty())
                return false;
            else
            {
                char ch = ss.top();
                ss.pop();

                if (s[i] == ')' && (ch == '{' || ch == '['))
                    return false;
                else if (s[i] == '}' && (ch == '(' || ch == '['))
                    return false;
                else if (s[i] == ']' && (ch == '{' || ch == '('))
                    return false;

                i++;
            };
        };
    }

    if (ss.empty())
    {
        return true;
    }
    else
    {
        return false;
    }

    return true;

}

//数组中出现次数超过一半的数字
int MoreThanHalfNum_Solution(vector<int>& numbers)
{
    int len = numbers.size();

    int max = 0, min = INT_MAX;
    for (size_t i = 0; i < len; i++)
    {
        if (numbers[i] < min)
            min = numbers[i];
        if (numbers[i] > max)
            max = numbers[i];
    }

    vector<int> cont;
    cont.resize(max - min + 1);

    for (size_t i = 0; i < len; i++)
    {
        cont[numbers[i] - min]++;
    }

    for (size_t i = 0; i < cont.size(); i++)
    {
        if (cont[i] > len / 2)
            return i + min;
    }

    return 0;
}

int main()
{
    isValid("([)]");

    vector<int> v({ 1,2,3,2,2,2,5,4,2 });
    MoreThanHalfNum_Solution(v);

	return 0;
}