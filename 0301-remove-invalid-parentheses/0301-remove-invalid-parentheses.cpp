class Solution {
public:
    unordered_set<string> found;

    void go(string &s, int i, int l, int r, int open, string &cur) {
        if (i == (int)s.size()) {
            if (l == 0 && r == 0 && open == 0) found.insert(cur);
            return;
        }
        char c = s[i];
        if (c == '(') {
            if (l > 0) go(s, i + 1, l - 1, r, open, cur);
            cur.push_back(c);
            go(s, i + 1, l, r, open + 1, cur);
            cur.pop_back();
        } else if (c == ')') {
            if (r > 0) go(s, i + 1, l, r - 1, open, cur);
            if (open > 0) {
                cur.push_back(c);
                go(s, i + 1, l, r, open - 1, cur);
                cur.pop_back();
            }
        } else {
            cur.push_back(c);
            go(s, i + 1, l, r, open, cur);
            cur.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') l++;
            else if (c == ')') {
                if (l > 0) l--;
                else r++;
            }
        }
        string cur;
        go(s, 0, l, r, 0, cur);
        return vector<string>(found.begin(), found.end());
    }
};