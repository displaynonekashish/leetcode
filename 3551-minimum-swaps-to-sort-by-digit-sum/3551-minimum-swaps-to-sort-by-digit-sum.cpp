class Solution {
public:
    int ds(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int,int>, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({{ds(nums[i]), nums[i]}, i});
        }
        sort(v.begin(), v.end());
        vector<int> to(n);
        for (int i = 0; i < n; i++) {
            to[v[i].second] = i;
        }
        vector<bool> seen(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            cycles++;
            int j = i;
            while (!seen[j]) {
                seen[j] = true;
                j = to[j];
            }
        }
        return n - cycles;
    }
};