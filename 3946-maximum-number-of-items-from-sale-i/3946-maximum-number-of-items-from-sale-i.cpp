class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_f = 1500;
        vector<int> freq(max_f + 1, 0);
        int min_p = 1e9;
        
        for (auto& it : items) {
            freq[it[0]]++;
            min_p = min(min_p, it[1]);
        }
        
        vector<int> mult(max_f + 1, 0);
        for (int f = 1; f <= max_f; f++) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= max_f; m += f) {
                mult[f] += freq[m];
            }
        }
        
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            int val = mult[items[i][0]];
            for (int c = budget; c >= p; c--) {
                if (dp[c - p] != -1) {
                    dp[c] = max(dp[c], dp[c - p] + val);
                }
            }
        }
        
        int ans = 0;
        for (int c = 0; c <= budget; c++) {
            if (dp[c] != -1) {
                ans = max(ans, dp[c] + (budget - c) / min_p);
            }
        }
        
        return ans;
    }
};