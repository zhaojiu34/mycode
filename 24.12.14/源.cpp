#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>

using namespace std;


class Finder {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        return quick_sort(a, 0, n - 1, n, K);
    }

    int quick_sort(vector<int>& a, int start, int end, int n, int k) {
        int base = a[start];
        int i = start;
        int j = end;
        int res = 0;

        while (i < j) {
            while (i < j && a[j] >= base) --j;
            while (i < j && a[i] <= base) ++i;
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[start], a[j]);

        if (n - j == k) return a[j];
        else if (n - j < k) res = quick_sort(a, start, j - 1, n, k);
        else if (n - j > k) res = quick_sort(a, j + 1, end, n, k);
        return res;
    }
};
