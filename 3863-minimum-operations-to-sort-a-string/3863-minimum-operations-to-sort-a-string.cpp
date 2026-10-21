class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool ok = true;
        char mn = s[0], mx = s[0];
        int a = 1, b = 1;
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c < s[i - 1]) ok = false;
            if (c < mn) { mn = c; a = 1; }
            else if (c == mn) a++;
            if (c > mx) { mx = c; b = 1; }
            else if (c == mx) b++;
        }
        if (ok) return 0;
        if (n == 2) return -1;
        if (s[0] == mn || s[n - 1] == mx) return 1;
        if (s[0] == mx && s[n - 1] == mn && a == 1 && b == 1) return 3;
        return 2;
    }
};