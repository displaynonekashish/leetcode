class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0)
                continue;

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            if (freq[a] == 0)
                continue;

            if (freq[b] == 0)
                continue;

            if (freq[c] == 0)
                continue;

           
            if (a == b && b == c) {
                if (freq[a] < 3) continue;
            }
            else if (a == b) {
                if (freq[a] < 2) continue;
            }
            else if (a == c) {
                if (freq[a] < 2) continue;
            }
            else if (b == c) {
                if (freq[b] < 2) continue;
            }

            ans++;
        }

        return ans;
    }
};