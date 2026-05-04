class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0) return 0;
        int j=s.length()-1; 
        int cnt =0;   
        while(j>=0 && s[j]==' ') j--;
        if(j<0) return 0;
        while(j>=0 && s[j]!=' '){
            j--;
            cnt++;
        }
        return cnt;
    }
};