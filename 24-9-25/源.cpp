#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s1;
    string s2;
    cin >> s1 >> s2;

    vector<string> v;

    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    if (s1 == "" || s2 == "")
        return -1;


    int n1 = -1, n2 = -1;

    for (size_t i = 0; i < n; i++)
    {
        if (v[i] == s1)
        {
            n1 = i;
            break;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        if (v[i] == s2)
        {
            n2 = i;
            break;
        }
    }

    if (n1 == -1 || n2 == -1)
        return -1;

    return abs(n2 - n1);
}

//int main()
//{
//    float a = 0.0;
//    char b = 0;
//    cin >> a >> b;
//
//    int sum = 0;
//
//    if (a <= 1)
//    {
//        sum += 20;
//    }
//    else
//    {
//        float i = a - 1;
//        sum += 20;
//
//        while (i >= 1)
//        {
//            sum += 1;
//            i -= 1;
//        }
//
//        if (i != 0)
//            sum += 1;
//
//    }
//
//    if (b == 'y')
//        sum += 5;
//
//    cout << sum << endl;
//}