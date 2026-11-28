class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> cnt(n + 1, 0), mult(n + 1, 0);
        for (auto& it : items) cnt[it[0]]++;
        for (int f = 1; f <= n; f++)
            for (int k = f; k <= n; k += f)
                mult[f] += cnt[k];

        long long m = LLONG_MAX;
        vector<pair<long long, long long>> v;
        for (auto& it : items) {
            m = min(m, (long long)it[1]);
            long long d = mult[it[0]] - 1;
            if (d > 0) v.push_back({it[1], d});
        }
        sort(v.begin(), v.end());

        long long r = budget, ans = 0;
        for (auto& [p, c] : v) {
            if (p >= 2 * m) break;
            long long t = min(c, r / p);
            ans += 2 * t;
            r -= t * p;
            if (t < c) break;
        }
        ans += r / m;
        return ans;
    }
};