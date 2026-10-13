class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a;
        for (int x : nums) a.push_back((long long)x * x);
        sort(a.begin(), a.end());
        int k = n / 2;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) ans -= a[i];
            else ans += a[i];
        }
        return ans;
    }
};