#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int cont = 0;
    for (size_t i = 0; i <= n; i++)
    {
        int m = pow(i, 2);
        int len = 0;

        if (i >= 0 && i <= 9)
            len = 1;
        else if (i >= 10 && i <= 99)
        {
            len = 2;
        }
        else if (i >= 100 && i <= 999)
        {
            len = 3;
        }
        else if (i >= 1000 && i <= 9999)
        {
            len = 4;
        }
        else
            len = 5;


        if (i == m % (int)pow(10, len))
        {
            cont++;
        }

    }

    cout << cont << endl;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")