class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        long long total = 0;

        for (char ch : s) {
            int index = ch - 'a';

            long long newCount = (total + 1) % MOD;

            
            total = (total - dp[index] + MOD) % MOD;

            
            dp[index] = newCount;

            total = (total + dp[index]) % MOD;
        }

        return total;
    }
};