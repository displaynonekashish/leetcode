class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];
        bool a = true, b = true;
        int x = k, y = k;

        for (int i = 0; i < n; i++) {
            if (nums[i] != x) a = false;
            if (nums[i] != y) b = false;
            if (!a && !b) return -1;
            if (++x == n) x = 0;
            if (--y < 0) y = n - 1;
        }

        int best = INT_MAX;
        if (a) {
            int left = (n - k) % n;
            int right = k == 0 ? 0 : k + 2;
            best = min(left, right);
        }
        if (b) {
            int s = (k + 1) % n;
            int left = (n - s) % n;
            best = min(best, 1 + min(s, left));
        }
        return best;
    }
};