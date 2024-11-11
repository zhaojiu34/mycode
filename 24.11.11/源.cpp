#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * ��ת����
     * @param n int���� ���鳤��
     * @param m int���� ���ƾ���
     * @param a int����vector ��������
     * @return int����vector
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        if (m == 0)
            return a;
        m = m % n;
        reverse(a.begin(), a.end());
        reverse(a.begin(), a.begin() + m);
        reverse(a.begin() + m, a.end());
        return a;
    }
};
