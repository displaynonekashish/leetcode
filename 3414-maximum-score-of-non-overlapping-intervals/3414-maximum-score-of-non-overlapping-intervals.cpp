class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        stable_sort(order.begin(), order.end(), [&](int a, int b){
            return intervals[a][1] < intervals[b][1];
        });

        vector<long long> L(n), R(n), W(n);
        vector<int> origIdx(n);
        for (int i = 0; i < n; i++) {
            int id = order[i];
            L[i] = intervals[id][0];
            R[i] = intervals[id][1];
            W[i] = intervals[id][2];
            origIdx[i] = id;
        }

        auto lexSmaller = [](const vector<int>& a, const vector<int>& b) {
            int m = min(a.size(), b.size());
            for (int i = 0; i < m; i++)
                if (a[i] != b[i]) return a[i] < b[i];
            return a.size() < b.size();
        };

     
        vector<vector<long long>> dpScore(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> dpList(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            int cur = i - 1;
            long long curL = L[cur];
            int p = lower_bound(R.begin(), R.end(), curL) - R.begin();

            for (int k = 1; k <= 4; k++) {
              
                dpScore[i][k] = dpScore[i - 1][k];
                dpList[i][k] = dpList[i - 1][k];

               
                long long cand = W[cur] + dpScore[p][k - 1];
                if (cand > dpScore[i][k]) {
                    vector<int> combined = dpList[p][k - 1];
                    combined.push_back(origIdx[cur]);
                    sort(combined.begin(), combined.end());
                    dpScore[i][k] = cand;
                    dpList[i][k] = combined;
                } else if (cand == dpScore[i][k]) {
                    vector<int> combined = dpList[p][k - 1];
                    combined.push_back(origIdx[cur]);
                    sort(combined.begin(), combined.end());
                    if (lexSmaller(combined, dpList[i][k]))
                        dpList[i][k] = combined;
                }
            }
        }

        return dpList[n][4];
    }
};