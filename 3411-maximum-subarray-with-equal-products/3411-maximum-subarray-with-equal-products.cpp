class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            long long p = 1;
            long long g = 0;
            long long l = 1;
            for (int j = i; j < n; j++) {
                p *= nums[j];
                if (p > 100000) break;
                g = __gcd(g, (long long)nums[j]);
                l = l / __gcd(l, (long long)nums[j]) * nums[j];
                if (p == l * g) best = max(best, j - i + 1);
            }
        }
        return best;
    }
};