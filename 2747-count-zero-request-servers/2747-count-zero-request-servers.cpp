class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        static int lh[1000002], qh[1000002];
        static int ln[100005], qn[100005], cnt[100005];

        int mx = 0;
        for (int q : queries) mx = max(mx, q);

        fill(lh, lh + mx + 2, -1);
        fill(qh, qh + mx + 2, -1);
        fill(cnt, cnt + n + 1, 0);

        int m = logs.size();
        for (int i = 0; i < m; i++) {
            int t = logs[i][1];
            if (t <= mx) {
                ln[i] = lh[t];
                lh[t] = i;
            }
        }

        int q = queries.size();
        for (int i = 0; i < q; i++) {
            qn[i] = qh[queries[i]];
            qh[queries[i]] = i;
        }

        vector<int> ans(q);
        int active = 0;

        for (int t = 1; t <= mx; t++) {
            for (int i = lh[t]; i != -1; i = ln[i]) {
                if (cnt[logs[i][0]]++ == 0) active++;
            }
            int old = t - x - 1;
            if (old >= 1) {
                for (int i = lh[old]; i != -1; i = ln[i]) {
                    if (--cnt[logs[i][0]] == 0) active--;
                }
            }
            for (int i = qh[t]; i != -1; i = qn[i]) {
                ans[i] = n - active;
            }
        }
        return ans;
    }
};