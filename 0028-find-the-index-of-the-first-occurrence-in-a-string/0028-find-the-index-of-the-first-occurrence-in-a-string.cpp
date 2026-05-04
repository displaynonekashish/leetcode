class Solution {
public:
    int strStr(string s, string n) {
        int sl = s.length();
        int nl = n.length();

        for(int i = 0; i <= sl - nl; i++) {
            int j = 0;
            while(j < nl && s[i + j] == n[j]) {
                j++;
            }
            if(j == nl) return i;
        }
        return -1;
    }
};