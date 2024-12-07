#define _CRT_SECURE_NO_WARNINGS 1

public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ����·������󳤶�
     * @param matrix int����vector<vector<>> ���������ÿ����
     * @return int����
     */
     //iΪ��,jΪ�У�preΪ��һ���ڵ��ֵ
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int pre) {
        if (matrix[i][j] <= pre)//���������
            return 0;
        if (dp[i][j] != -1)//�Ӹõ㿪ʼ����󳤶��Ѿ��������
            return dp[i][j];
        int mlen = 0;//����
        if (i - 1 >= 0)//����
            mlen = max(mlen, DFS(matrix, dp, i - 1, j, matrix[i][j]));
        if (i + 1 < matrix.size())//����
            mlen = max(mlen, DFS(matrix, dp, i + 1, j, matrix[i][j]));
        if (j + 1 < matrix[0].size())//����
            mlen = max(mlen, DFS(matrix, dp, i, j + 1, matrix[i][j]));
        if (j - 1 >= 0)//����
            mlen = max(mlen, DFS(matrix, dp, i, j - 1, matrix[i][j]));
        //�ڵ�������һ������
        dp[i][j] = mlen + 1;
        return dp[i][j];
    }
    int solve(vector<vector<int> >& matrix) {
        if (matrix.size() == 0)
            return 0;
        int n = matrix.size();//��
        int m = matrix[0].size();//��
        //dpΪ��ά���飬�����Ըõ�Ϊ��ʼ�����ߵ��·����
        vector <vector<int>> dp(n, vector<int>(m, -1));
        int len = 0;
        //��ÿ���㶼��Ϊ��ʼ��ʹ��DFS����һ��
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                len = max(len, DFS(matrix, dp, i, j, -1));//��Ϊ����ʼ�㣬����ǰһ���ڵ���Ϊ-1
            }
        }
        return len;
    }
};
