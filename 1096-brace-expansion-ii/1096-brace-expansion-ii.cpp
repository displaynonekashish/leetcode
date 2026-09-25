class Solution {
public:
    int i = 0;

    set<string> parseExpr(string &s) {
        set<string> res = parseTerm(s);

        while (i < s.size() && s[i] == ',') {
            i++;  

            set<string> next = parseTerm(s);
            res.insert(next.begin(), next.end());
        }

        return res;
    }


    set<string> parseTerm(string &s) {
        set<string> res;
        res.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = parseFactor(s);

            set<string> temp;


            for (const string &a : res) {
                for (const string &b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        return res;
    }

  
    set<string> parseFactor(string &s) {
        set<string> res;

        if (s[i] == '{') {
            i++;  

            res = parseExpr(s);

            i++;  
        } 
        else {
            res.insert(string(1, s[i]));
            i++;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> ans = parseExpr(expression);

        return vector<string>(ans.begin(), ans.end());
    }
};