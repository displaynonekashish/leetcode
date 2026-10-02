class Solution {
public:
    vector<string> res;

    void go(string s, int open, int close, int n) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (open < n) go(s + "(", open + 1, close, n);
        if (close < open) go(s + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        go("", 0, 0, n);
        return res;
    }
};