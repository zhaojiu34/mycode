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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算成功举办活动需要多少名主持人
     * @param n int整型 有n个活动
     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
     * @return int整型
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
