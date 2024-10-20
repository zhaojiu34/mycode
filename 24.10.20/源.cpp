#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    int n, m, f[40005], vis[40005];
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    int getid(int x, int y) { // 为方格中每个点编号
        return x * m + y;
    }
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void merge(int a, int b, int x, int y) {
        int k1 = find(getid(a, b)), k2 = find(getid(x, y));
        if (k1 != k2) f[k1] = k2;
    }
    bool Judge(int x, int y) { // 判断一个点是否出界
        return x >= 0 && x < n&& y >= 0 && y < m;
    }
    int solve(vector<vector<char> >& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n * m; ++i) vis[i] = 0, f[i] = i;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (Judge(x, y) && grid[x][y] == '1' && grid[i][j] == '1') merge(x, y, i, j);
                }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == '1') vis[find(getid(i, j))] = 1;
        int ans = 0;
        for (int i = 0; i < n * m; ++i)
            ans += vis[i];
        return ans;

    }
};