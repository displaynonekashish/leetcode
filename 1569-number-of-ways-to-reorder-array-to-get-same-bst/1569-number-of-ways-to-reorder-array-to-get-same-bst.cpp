class Solution {
public:
    long long M = 1000000007;
    vector<vector<long long>> c;

    long long solve(vector<int> v) {
        int n = v.size();
        if (n <= 2) return 1;
        vector<int> l, r;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[0]) l.push_back(v[i]);
            else r.push_back(v[i]);
        }
        long long a = solve(l);
        long long b = solve(r);
        long long w = c[n - 1][l.size()];
        return w * a % M * b % M;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        c.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
            }
        }
        long long ans = solve(nums);
        return (ans - 1 + M) % M;
    }
};