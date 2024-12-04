#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int dfs(vector<vector<int> >& mat, int x, int y, int pre) {
        // 如果到达这个位置的时候的长度大于等于之前得到的所有的位置
        if (pre >= mat[x][y]) {
            return 0;
        }
        int mx = 0;
        // 记录这个位置开始往四个方向遍历得到的最长的长度，类似于记忆化搜索
        if (x + 1 < mat.size()) {
            mx = max(mx, dfs(mat, x + 1, y, mat[x][y]));
        }
        if (x - 1 >= 0) {
            mx = max(mx, dfs(mat, x - 1, y, mat[x][y]));
        }
        if (y - 1 >= 0) {
            mx = max(mx, dfs(mat, x, y - 1, mat[x][y]));
        }
        if (y + 1 < mat[0].size()) {
            mx = max(mx, dfs(mat, x, y + 1, mat[x][y]));
        }

        return mx + 1;
    }
    int solve(vector<vector<int> >& matrix) {
        // write code here
        int n = matrix.size();
        // 特判矩阵为空的情况
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 枚举每个起点的位置
                ans = max(ans, dfs(matrix, i, j, -1));
            }
        }

        return ans;
    }
};
