class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        multiset<int> lo, hi;
        long long slo = 0, shi = 0;
        int need = (x + 1) / 2;

        auto balance = [&]() {
            while ((int)lo.size() > need) {
                int v = *lo.rbegin();
                lo.erase(prev(lo.end()));
                slo -= v;
                hi.insert(v);
                shi += v;
            }
            while ((int)lo.size() < need && !hi.empty()) {
                int v = *hi.begin();
                hi.erase(hi.begin());
                shi -= v;
                lo.insert(v);
                slo += v;
            }
        };

        for (int i = 0; i < n; i++) {
            int v = nums[i];
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                slo += v;
            } else {
                hi.insert(v);
                shi += v;
            }
            if (i >= x) {
                int out = nums[i - x];
                if (out <= *lo.rbegin()) {
                    lo.erase(lo.find(out));
                    slo -= out;
                } else {
                    hi.erase(hi.find(out));
                    shi -= out;
                }
            }
            balance();
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - slo + shi - med * (long long)hi.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;
        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x && dp[j - 1][i - x] < INF) {
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
                }
            }
        }
        return dp[k][n];
    }
};