class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            int prevMax = 0;
            for (int s = 0; s < n && ok; s += k) {
                int d = 0, mn = INT_MAX, mx = 0;
                for (int j = s; j < s + k; j++) {
                    int nx = (j + 1 == s + k) ? s : j + 1;
                    if (nums[j] > nums[nx]) d++;
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }
                if (d > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) ans += k;
        }
        return ans;
    }
};