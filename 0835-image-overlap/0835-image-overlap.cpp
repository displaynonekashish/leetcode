class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> a, b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) a.push_back({i, j});
                if (img2[i][j]) b.push_back({i, j});
            }
        }

        vector<vector<int>> cnt(2 * n - 1, vector<int>(2 * n - 1));
        int ans = 0;

        for (auto p1 : a) {
            for (auto p2 : b) {
                int x = p2.first - p1.first + n - 1;
                int y = p2.second - p1.second + n - 1;

                cnt[x][y]++;
                ans = max(ans, cnt[x][y]);
            }
        }

        return ans;
    }
};