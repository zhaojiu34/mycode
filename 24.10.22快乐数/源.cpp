#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>

using namespace std;

bool isHappy1(int n)
{
    int sum = 0;
    int a = n;

    while (a)
    {
        sum += pow(a % 10, 2);
        a /= 10;
    }

    while (sum >= 10 || sum == 7)
    {
        int num = sum;
        sum = 0;
        while (num)
        {
            sum += pow(num % 10, 2);
            num /= 10;
        }

    }

    if (sum == 1)
        return true;
    else
        return false;

}


bool isHappy(int n)
{
    int fast = 0, slow = 0;

    int sumslow = 0,sumfast = 0;
    int aslow = n,afast = 0;
    while (aslow)
    {
        sumslow += pow(aslow % 10, 2);
        aslow /= 10;
    }
    slow = sumfast;

    afast = n;
    sumfast = 0;
    while (afast)
    {
        sumfast += pow(afast % 10, 2);
        afast /= 10;
    }
    fast = sumfast;

    while (fast != slow)
    {

        aslow = sumslow;
        sumslow = 0;
        while (aslow)
        {
            sumslow += pow(aslow % 10, 2);
            aslow /= 10;
        }
        slow = sumslow;


        afast = sumfast;
        sumfast = 0;
        while (afast)
        {
            sumfast += pow(afast % 10, 2);
            afast /= 10;
        }
        afast = sumfast;
        sumfast = 0;
        while (afast)
        {
            sumfast += pow(afast % 10, 2);
            afast /= 10;
        }
        fast = sumfast;

    }

    if (fast == 1)
        return true;
    else
        return false;

}
int main()
{
   isHappy(1111111);

    return 0;
}