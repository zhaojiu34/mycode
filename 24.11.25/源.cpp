#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int n, m;

    int dfs(int i, int j, vector<vector<int> >& matrix, int cur = 0) {
        if (i == n - 1 && j == m - 1) {
            return cur;
        }
        else {
            cur += matrix[i][j];
            if (i == n - 1) {
                return dfs(i, j + 1, matrix, cur); // 只能往下走
            }
            else if (j == m - 1) {
                return dfs(i + 1, j, matrix, cur); // 只能往右走
            }
            else {
                // 都能走，取最小的
                return min(dfs(i, j + 1, matrix, cur), dfs(i + 1, j, matrix, cur));
            }

        }

    }
    int minPathSum(vector<vector<int> >& matrix) {
        n = matrix.size(), m = matrix[0].size();


        return dfs(0, 0, matrix, 0);
    }
};
