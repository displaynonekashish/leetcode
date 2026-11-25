class Solution {
public:
    typedef unsigned long long ull;
    const ull M = (1ULL << 61) - 1;

    ull mul(ull a, ull b) {
        __uint128_t t = (__uint128_t)a * b;
        ull r = (t & M) + (t >> 61);
        if (r >= M) r -= M;
        return r;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        ull B = rng() % (M - 1000) + 500;

        vector<ull> h(n + 1, 0), pw(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = (mul(h[i], B) + nums[i]) % M;
            pw[i + 1] = mul(pw[i], B);
        }

        auto ok = [&](int L) {
            vector<ull> v;
            for (int i = 0; i + L <= n; i++) {
                ull x = (h[i + L] + M - mul(h[i], pw[L])) % M;
                v.push_back(x);
            }
            sort(v.begin(), v.end());
            int m = v.size();
            for (int i = 0; i < m; i++) {
                bool same_left = i > 0 && v[i] == v[i - 1];
                bool same_right = i + 1 < m && v[i] == v[i + 1];
                if (!same_left && !same_right) return true;
            }
            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};