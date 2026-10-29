class Solution {
public:
    int n;
    vector<int> bit;
    vector<int> tin, tout, dep;
    vector<vector<int>> up;

    void add(int i, int v) {
        for (i++; i <= n + 1; i += i & -i) bit[i] ^= v;
    }

    int get(int i) {
        int r = 0;
        for (i++; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }

    void rangeAdd(int l, int r, int v) {
        add(l, v);
        add(r + 1, v);
    }

    int lca(int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);
        int d = dep[a] - dep[b];
        for (int k = 0; k < 16; k++)
            if (d >> k & 1) a = up[k][a];
        if (a == b) return a;
        for (int k = 15; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        bit.assign(n + 3, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        dep.assign(n, 0);
        up.assign(16, vector<int>(n, 0));
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int timer = 0;
        vector<pair<int, int>> st;
        st.push_back({0, 0});
        tin[0] = timer++;
        up[0][0] = 0;
        while (!st.empty()) {
            int v = st.back().first;
            int &i = st.back().second;
            if (i < (int)g[v].size()) {
                int w = g[v][i++];
                if (w == up[0][v] && v != 0) continue;
                if (w == up[0][v] && v == 0 && w == 0) continue;
                up[0][w] = v;
                dep[w] = dep[v] + 1;
                tin[w] = timer++;
                st.push_back({w, 0});
            } else {
                tout[v] = timer - 1;
                st.pop_back();
            }
        }

        for (int k = 1; k < 16; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        for (int v = 0; v < n; v++)
            rangeAdd(tin[v], tout[v], 1 << (s[v] - 'a'));

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string cmd;
            ss >> cmd;
            if (cmd == "update") {
                int u;
                char c;
                ss >> u >> c;
                int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                s[u] = c;
                rangeAdd(tin[u], tout[u], d);
            } else {
                int a, b;
                ss >> a >> b;
                int l = lca(a, b);
                int m = get(tin[a]) ^ get(tin[b]) ^ (1 << (s[l] - 'a'));
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};