#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ����·������󳤶�
     * @param matrix int����vector<vector<>> ���������ÿ����
     * @return int����
     */
    int dfs(vector<vector<int> >& mat, int x, int y, int pre) {
        // ����������λ�õ�ʱ��ĳ��ȴ��ڵ���֮ǰ�õ������е�λ��
        if (pre >= mat[x][y]) {
            return 0;
        }
        int mx = 0;
        // ��¼���λ�ÿ�ʼ���ĸ���������õ�����ĳ��ȣ������ڼ��仯����
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
        // ���о���Ϊ�յ����
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // ö��ÿ������λ��
                ans = max(ans, dfs(matrix, i, j, -1));
            }
        }

        return ans;
    }
};
