class Solution {
public:
    const long long M = 1000000007;
    vector<long long> a, b, z;

    void app(int o, int len, long long v) {
        b[o] = (b[o] + 2 * v % M * a[o] + v * v % M * len) % M;
        a[o] = (a[o] + v * len) % M;
        z[o] = (z[o] + v) % M;
    }

    void down(int o, int l, int r) {
        if (z[o]) {
            int m = (l + r) / 2;
            app(2 * o, m - l + 1, z[o]);
            app(2 * o + 1, r - m, z[o]);
            z[o] = 0;
        }
    }

    void upd(int o, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            app(o, r - l + 1, 1);
            return;
        }
        down(o, l, r);
        int m = (l + r) / 2;
        if (x <= m) upd(2 * o, l, m, x, y);
        if (y > m) upd(2 * o + 1, m + 1, r, x, y);
        a[o] = (a[2 * o] + a[2 * o + 1]) % M;
        b[o] = (b[2 * o] + b[2 * o + 1]) % M;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        a.assign(4 * n, 0);
        b.assign(4 * n, 0);
        z.assign(4 * n, 0);
        vector<int> last(100001, -1);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            upd(1, 0, n - 1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + b[1]) % M;
        }
        return ans;
    }
};