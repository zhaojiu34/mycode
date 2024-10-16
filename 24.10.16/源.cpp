#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<string>
#include <vector>
#include<algorithm>

using namespace std;

////Ìí¼Ó¶ººÅ
//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    int cont = 0;
//    string s;
//    while (n)
//    {
//        if (cont == 3)
//        {
//            s += ',';
//            cont = 0;
//        }
//
//        s += (n % 10)+'0';
//        n /= 10;
//        cont++;
//    }
//
//    string ret(s.rbegin(), s.rend());
//    cout << ret;
//
//    return 0;
//}


//ÌøÌ¨½×
//int func(int n)
//{
//    if (n == 0)
//        return 0;
//    if (n == 1)
//        return 1;
//    if (n == 2)
//        return 2;
//
//    return func(n - 1) + func(n - 2) ;
//}
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    cout << func(n);
//}

//ÆË¿ËÅÆË³×Ó
bool IsContinuous(vector<int>& numbers)
{
    sort(numbers.begin(), numbers.end());

    int cont = 0;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
            cont++;
    }

    if (cont == 0)
    {
        for (size_t i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] != 0 && numbers[i + 1] - numbers[i] > 1)
            {
                return false;
            }
        }
        return true;
        ;
    }
    else if (cont == 1)
    {
        int a = 0;
        for (size_t i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 2)
            {
                a++;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] > 2)
            {
                return false;
            }
        }

        if (a >= 2)
            return false;
        else
            return true;
        ;
    }

    else if (cont == 2)
    {
        int a = 0;
        for (size_t i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 3)
            {
                a += 2;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 2)
            {
                a++;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] > 3)
            {
                return false;
            }
        }

        if (a >= 3)
            return false;
        else
            return true;
        ;
    }

    else if (cont == 3)
    {
        int a = 0;
        for (size_t i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] != 0 && numbers[i] != 0 && numbers[i + 1] - numbers[i] == 3)
            {
                a += 2;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 2)
            {
                a++;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 4)
            {
                a += 3;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] > 4)
            {
                return false;
            }
        }

        if (a >= 4)
            return false;
        else
            return true;
        ;
    }

    else if (cont == 4)
    {
        int a = 0;
        for (size_t i = 0; i < numbers.size() - 1; i++)
        {
            if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 3)
            {
                a += 2;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 2)
            {
                a++;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 4)
            {
                a += 3;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] == 5)
            {
                a += 4;
            }
            else if (numbers[i] != 0 && numbers[i + 1] - numbers[i] > 4)
            {
                return false;
            }
        }

        if (a >= 5)
            return false;
        else
            return true;
        ;
    }

    return true;

}