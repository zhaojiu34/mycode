#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ����·������󳤶�
     * @param matrix int����vector<vector<>> ���������ÿ����
     * @return int����
     */
     // ���仯�����������
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& mem) {
        // ��mem[i][j]==0֤�������û���߹�
        // ���������߹��ˣ���ֱ�ӷ��أ����м�֦
        if (mem[i][j] != 0)
            return mem[i][j];
        ++mem[i][j];
        for (int a = 0; a < 4; a++) {
            int newI = i + dx[a];
            int newJ = j + dy[a];
            if (newI >= 0 && newI < matrix.size() && newJ >= 0 && newJ < matrix[0].size() && matrix[newI][newJ] > matrix[i][j])
                mem[i][j] = max(mem[i][j], dfs(matrix, newI, newJ, mem) + 1);
        }
        return mem[i][j];
    }
    int solve(vector<vector<int> >& matrix) {
        // write code here
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 0 || m == 0)
            return 0;
        int ans = 1;
        // ����һ����������������������ÿ���㿪ʼ�������·���������м�֦����
        vector<vector<int>> mem(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // ans��¼ȫ�����
                // dfs��¼i��jλ�ÿ�ʼ���·��
                ans = max(ans, dfs(matrix, i, j, mem));
            }
        }
        return ans;
    }
};
