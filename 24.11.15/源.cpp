#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
     // 记忆化深度优先搜索
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& mem) {
        // 当mem[i][j]==0证明这个点没有走过
        // 如果这个点走过了，就直接返回，进行剪枝
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
        // 设置一个记忆矩阵用来保存矩阵中每个点开始的最长递增路径，来进行剪枝操作
        vector<vector<int>> mem(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // ans记录全局最大
                // dfs记录i，j位置开始的最长路径
                ans = max(ans, dfs(matrix, i, j, mem));
            }
        }
        return ans;
    }
};
