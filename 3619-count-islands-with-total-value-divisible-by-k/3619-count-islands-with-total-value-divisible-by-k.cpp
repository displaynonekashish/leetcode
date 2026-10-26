class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int d[5] = {-1, 0, 1, 0, -1};
        vector<int> st;
        st.reserve(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;

                long long sum = 0;
                st.clear();
                st.push_back(i * n + j);
                sum += grid[i][j];
                grid[i][j] = 0;

                while (!st.empty()) {
                    int p = st.back();
                    st.pop_back();

                    int x = p / n, y = p % n;

                    for (int z = 0; z < 4; ++z) {
                        int nx = x + d[z];
                        int ny = y + d[z + 1];

                        if (nx >= 0 && nx < m &&
                            ny >= 0 && ny < n &&
                            grid[nx][ny] > 0) {
                            sum += grid[nx][ny];
                            grid[nx][ny] = 0;
                            st.push_back(nx * n + ny);
                        }
                    }
                }

                if (sum % k == 0) ++ans;
            }
        }

        return ans;
    }
};