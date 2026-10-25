class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        vector<pair<int, int>> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;

                bool closed = true;
                st.clear();
                st.push_back({i, j});
                grid[i][j] = 1;

                while (!st.empty()) {
                    auto [x, y] = st.back();
                    st.pop_back();

                    if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
                        closed = false;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dirs[k];
                        int ny = y + dirs[k + 1];

                        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                            grid[nx][ny] == 0) {
                            grid[nx][ny] = 1;
                            st.push_back({nx, ny});
                        }
                    }
                }

                ans += closed;
            }
        }

        return ans;
    }
};