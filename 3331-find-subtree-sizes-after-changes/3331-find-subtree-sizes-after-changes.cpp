class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) g[parent[i]].push_back(i);

        vector<int> np(parent), order, prev(n), it(n, 0);
        int last[26];
        for (int i = 0; i < 26; i++) last[i] = -1;

        stack<int> st;
        int c = s[0] - 'a';
        prev[0] = last[c];
        last[c] = 0;
        order.push_back(0);
        st.push(0);

        while (!st.empty()) {
            int v = st.top();
            if (it[v] < (int)g[v].size()) {
                int u = g[v][it[v]++];
                int d = s[u] - 'a';
                if (last[d] != -1) np[u] = last[d];
                prev[u] = last[d];
                last[d] = u;
                order.push_back(u);
                st.push(u);
            } else {
                last[s[v] - 'a'] = prev[v];
                st.pop();
            }
        }

        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int v = order[i];
            ans[np[v]] += ans[v];
        }
        return ans;
    }
};