#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
            return true;

        if (n < 3)
            return false;

        while (n > 1)
        {
            if (n % 3 != 0)
                return false;

            n /= 3;
        }

        return true;
    }
};

int main()
{

}