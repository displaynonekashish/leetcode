class Solution {
public:
    struct Node {
        int prod;
        int pref[5];

        Node(int k = 1) {
            prod = 1;
            for (int i = 0; i < 5; i++) pref[i] = 0;
        }
    };

    int n, K;
    vector<Node> seg;

    Node mergeNode(const Node& A, const Node& B) {
        Node C;
        C.prod = (A.prod * B.prod) % K;

        for (int r = 0; r < K; r++) {
            C.pref[r] += A.pref[r];
        }

        for (int r = 0; r < K; r++) {
            int newRem = (A.prod * r) % K;
            C.pref[newRem] += B.pref[r];
        }

        return C;
    }

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[idx].prod = nums[l] % K;
            seg[idx].pref[seg[idx].prod] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, nums);
        build(idx * 2 + 1, mid + 1, r, nums);

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx].prod = val % K;

            for (int i = 0; i < K; i++)
                seg[idx].pref[i] = 0;

            seg[idx].pref[seg[idx].prod] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return Node();
        }

        if (ql <= l && r <= qr) {
            return seg[idx];
        }

        int mid = (l + r) / 2;

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        n = nums.size();
        K = k;

        seg.resize(4 * n);
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];


            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};