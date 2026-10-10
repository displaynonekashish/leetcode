class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int mx = 100000;
        vector<long long> cnt(mx + 2, 0);
        for (int i = 0; i < nums1.size(); i++) {
            cnt[abs(nums1[i] - nums2[i])]++;
        }
        for (int v = mx; v > 0 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            if (cnt[v] <= k) {
                k -= cnt[v];
                cnt[v - 1] += cnt[v];
                cnt[v] = 0;
            } else {
                cnt[v] -= k;
                cnt[v - 1] += k;
                k = 0;
            }
        }
        long long ans = 0;
        for (long long v = 0; v <= mx; v++) {
            ans += cnt[v] * v * v;
        }
        return ans;
    }
};