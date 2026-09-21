class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0);
        for (int num : nums) {
            int a = num % k;
            vector<long long> newcnt(k, 0);
            for (int r = 0; r < k; r++) {
                if (cnt[r]) newcnt[(r * a) % k] += cnt[r];
            }
            newcnt[a] += 1;
            cnt = newcnt;
            for (int r = 0; r < k; r++) result[r] += cnt[r];
        }
        return result;
    }
};