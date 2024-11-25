#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     *
     * @param matrix int����vector<vector<>> the matrix
     * @return int����
     */
    int n, m;

    int dfs(int i, int j, vector<vector<int> >& matrix, int cur = 0) {
        if (i == n - 1 && j == m - 1) {
            return cur;
        }
        else {
            cur += matrix[i][j];
            if (i == n - 1) {
                return dfs(i, j + 1, matrix, cur); // ֻ��������
            }
            else if (j == m - 1) {
                return dfs(i + 1, j, matrix, cur); // ֻ��������
            }
            else {
                // �����ߣ�ȡ��С��
                return min(dfs(i, j + 1, matrix, cur), dfs(i + 1, j, matrix, cur));
            }

        }

    }
    int minPathSum(vector<vector<int> >& matrix) {
        n = matrix.size(), m = matrix[0].size();


        return dfs(0, 0, matrix, 0);
    }
};
