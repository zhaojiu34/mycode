#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0 || n < 0)
            return false;

        while (n > 1)
        {
            if (n % 2 != 0)
            {
                return false;
            }

            n /= 2;
        }

        return true;
    }
};

int main()
{

    cout << Solution().isPowerOfTwo(16);


    return 0;
}


int main()
{

    cout << Solution().isPowerOfTwo(16);


    return 0;
}
