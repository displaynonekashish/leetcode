class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, long long>> dq;
        long long sp = 0, sn = 0, ans = 0;
        int r = n - 1;
        for (int l = n - 1; l >= 0; l--) {
            long long c = 1;
            sp += nums[l];
            sn += nums[l];
            while (!dq.empty() && dq.front().first <= nums[l]) {
                sp -= dq.front().first * dq.front().second;
                sp += (long long)nums[l] * dq.front().second;
                c += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], c});
            while (sp - sn > k) {
                sp -= dq.back().first;
                sn -= nums[r];
                dq.back().second--;
                if (dq.back().second == 0) dq.pop_back();
                r--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};