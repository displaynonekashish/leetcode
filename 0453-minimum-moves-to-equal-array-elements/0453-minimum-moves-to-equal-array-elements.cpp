class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0];
        for (int x : nums) {
            if (x < mn) mn = x;
        }
        long long total = 0;
        for (int x : nums) {
            total += (long long)x - mn;
        }
        return (int)total;
    }
};