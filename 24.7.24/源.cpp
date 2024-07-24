#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


class Solution1 {
public:
    int exchangeBits(int num) {
        return ((num & 0x55555555) << 1) | ((num & 0xaaaaaaaa) >> 1);
    }
};

class Solution2 {
public:
    int multiply(int A, int B)
    {
        if (A < B)
            return  _multiply(A, B);
        else
            return _multiply(B, A);
    }

    int _multiply(int A, int B)
    {
        if (A == 1)
            return B;
        else
        {
            int num = _multiply(A - 1, B);
            return num + B;
        }

    }


};



//namespace Solution3
//{
//    bool Func(size_t i = 0)
//    {
//        if (i >= 1 && i <= 9)
//        {
//            if (i == 7)
//                return true;
//        }
//
//        if (i >= 10 && i <= 99)
//        {
//            if (i % 10 == 7 || i / 10 == 7)
//                return true;
//        }
//
//        if (i >= 100 && i <= 999)
//        {
//            if (i % 10 == 7 || i / 100 == 7 || i / 10 % 10 == 7)
//                return true;
//        }
//
//        if (i >= 1000 && i <= 9999)
//        {
//            if (i % 10 == 7 || i / 1000 == 7 || i / 10 % 10 == 7 || i / 100 % 10 == 7)
//                return true;
//        }
//
//        if (i >= 10000 && i <= 30000)
//        {
//            if (i % 10 == 7 || i / 10000 == 7 || i / 10 % 10 == 7 || i / 100 % 10 == 7 || i / 1000 % 10 == 7)
//                return true;
//        }
//
//        return false;
//
//    }
//
//    int main()
//    {
//        int cont = 0;
//        int n = 0;
//        cin >> n;
//
//        for (size_t i = 1; i <= n; i++)
//        {
//            if (i % 7 == 0 && !Func(i))
//            {
//                cont++;
//            }
//
//            if (Func(i))
//                cont++;
//
//
//        }
//
//        cout << cont << endl;
//
//    }
//}

//int main()
//{
//    double d;
//    cin >> d;
//
//    if (d - (int)d >= 0.5)
//    {
//        cout << (int)d + 1 << endl;
//    }
//    else
//    {
//        cout << (int)d << endl;
//    }
//}



//int main()
//{
//    int n = 0;
//    cin >> n;
//
//    vector<int> v1;
//    v1.resize(n);
//    for (size_t i = 0; i < n; i++)
//    {
//        cin >> v1[i];
//    }
//
//    int max = v1[0];
//    for (const auto& e : v1)
//    {
//        if (max < e)
//        {
//            max = e;
//        }
//    }
//
//    vector<int> v2;
//    v2.resize(max);
//    v2[0] = 1, v2[1] = 2;
//
//    for (size_t i = 2; i < max; i++)
//    {
//        v2[i] = (v2[i - 1] * 2 + v2[i - 2]) % 32767;
//    }
//
//    for (size_t i = 0; i < n; i++)
//    {
//        cout << v2[v1[i] - 1] << endl;
//    }
//}


//int main()
//{
//    string s;
//
//    int cont = 0, num = 0, sl = 0, el = 0;
//
//    while (cin >> s)
//    {
//        sl++;
//        for (const auto& e : s)
//        {
//            if (e >= 'a' && e <= 'z')
//                cont++;
//            else if (e >= '0' && e <= '9')
//                num++;
//            else
//                el++;
//        }
//    }
//
//    cout << cont << endl << sl - 1 << endl << num << endl << el << endl;
//}
