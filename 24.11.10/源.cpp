#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ����ɹ��ٰ���Ҫ������������
     * @param n int���� ��n���
     * @param startEnd int����vector<vector<>> startEnd[i][0]���ڱ�ʾ��i����Ŀ�ʼʱ�䣬startEnd[i][1]��ʾ��i����Ľ���ʱ��
     * @return int����
     */
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        // write code here
        if (startEnd.empty()) {
            return 0;
        }
        sort(startEnd.begin(), startEnd.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(startEnd[0][1]);
        for (int i = 1; i < startEnd.size(); i++) {
            if (startEnd[i][0] < pq.top()) {
                pq.push(startEnd[i][1]);
            }
            else {
                pq.pop();
                pq.push(startEnd[i][1]);
            }
        }
        return pq.size();
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};
