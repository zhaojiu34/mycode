#define _CRT_SECURE_NO_WARNINGS 1

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
     //i为行,j为列，pre为上一个节点的值
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int pre) {
        if (matrix[i][j] <= pre)//不满足递增
            return 0;
        if (dp[i][j] != -1)//从该点开始的最大长度已经求出来了
            return dp[i][j];
        int mlen = 0;//不走
        if (i - 1 >= 0)//左移
            mlen = max(mlen, DFS(matrix, dp, i - 1, j, matrix[i][j]));
        if (i + 1 < matrix.size())//右移
            mlen = max(mlen, DFS(matrix, dp, i + 1, j, matrix[i][j]));
        if (j + 1 < matrix[0].size())//下移
            mlen = max(mlen, DFS(matrix, dp, i, j + 1, matrix[i][j]));
        if (j - 1 >= 0)//上移
            mlen = max(mlen, DFS(matrix, dp, i, j - 1, matrix[i][j]));
        //节点自身算一个长度
        dp[i][j] = mlen + 1;
        return dp[i][j];
    }
    int solve(vector<vector<int> >& matrix) {
        if (matrix.size() == 0)
            return 0;
        int n = matrix.size();//行
        int m = matrix[0].size();//列
        //dp为二维数组，保存以该点为起始点能走的最长路径。
        vector <vector<int>> dp(n, vector<int>(m, -1));
        int len = 0;
        //以每个点都作为起始点使用DFS遍历一遍
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                len = max(len, DFS(matrix, dp, i, j, -1));//因为是起始点，所以前一个节点设为-1
            }
        }
        return len;
    }
};
