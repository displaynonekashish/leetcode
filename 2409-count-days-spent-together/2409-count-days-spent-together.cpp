class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int days[] = {0, 31, 59, 90, 120, 151,
                      181, 212, 243, 273, 304, 334};

        auto convert = [&](string s) {
            return days[stoi(s.substr(0, 2)) - 1]
                   + stoi(s.substr(3, 2));
        };

        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        return max(0, end - start + 1);
    }
};