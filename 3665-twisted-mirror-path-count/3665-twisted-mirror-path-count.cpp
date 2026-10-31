class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1000000007;
        vector<int> R(m * n, 0), D(m * n, 0);
        R[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                int r = R[id], d = D[id];
                if (r == 0 && d == 0) continue;
                if (grid[i][j] == 0) {
                    int t = r + d;
                    if (t >= MOD) t -= MOD;
                    if (j + 1 < n) {
                        int x = R[id + 1] + t;
                        if (x >= MOD) x -= MOD;
                        R[id + 1] = x;
                    }
                    if (i + 1 < m) {
                        int x = D[id + n] + t;
                        if (x >= MOD) x -= MOD;
                        D[id + n] = x;
                    }
                } else {
                    if (i + 1 < m) {
                        int x = D[id + n] + r;
                        if (x >= MOD) x -= MOD;
                        D[id + n] = x;
                    }
                    if (j + 1 < n) {
                        int x = R[id + 1] + d;
                        if (x >= MOD) x -= MOD;
                        R[id + 1] = x;
                    }
                }
            }
        }
        int ans = R[m * n - 1] + D[m * n - 1];
        if (ans >= MOD) ans -= MOD;
        return ans;
    }
};