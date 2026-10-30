class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<int> st(n + 1, 0);
        for (auto& e : edges) st[e[0] + 1]++;
        for (int i = 0; i < n; i++) st[i + 1] += st[i];
        vector<int> to(edges.size()), wt(edges.size());
        vector<int> pos(st.begin(), st.end() - 1);
        for (auto& e : edges) {
            int p = pos[e[0]]++;
            to[p] = e[1];
            wt[p] = e[2];
        }
        const int INF = 1e9;
        vector<int> d((size_t)n * k, INF);
        vector<int> best(n, k + 1);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        d[0] = 0;
        pq.push(0);
        const long long mask = (1LL << 22) - 1;
        while (!pq.empty()) {
            long long key = pq.top();
            pq.pop();
            int dist = key >> 22;
            int s = key & mask;
            int u = s / k;
            int len = s % k + 1;
            if (dist > d[s]) continue;
            if (len >= best[u]) continue;
            best[u] = len;
            if (u == n - 1) return dist;
            for (int i = st[u]; i < st[u + 1]; i++) {
                int v = to[i];
                int nl = labels[v] == labels[u] ? len + 1 : 1;
                if (nl > k || nl >= best[v]) continue;
                int nd = dist + wt[i];
                int ns = v * k + nl - 1;
                if (nd < d[ns]) {
                    d[ns] = nd;
                    pq.push(((long long)nd << 22) | ns);
                }
            }
        }
        return -1;
    }
};