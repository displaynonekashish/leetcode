class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = cost1, b = cost2, c = costBoth;
        long long n1 = need1, n2 = need2;
        long long lo = min(n1, n2);
        long long hi = max(n1, n2);
        long long ks[3] = {0, lo, hi};
        long long best = LLONG_MAX;
        for (long long k : ks) {
            long long cur = k * c + max(0LL, n1 - k) * a + max(0LL, n2 - k) * b;
            best = min(best, cur);
        }
        return best;
    }
};