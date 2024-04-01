class Solution {
public:
    int lengthOfLastWord(string s) {
       int i=s.length()-1;
       int ct=0;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
       while(i>=0 && s[i] !=' ')
       {
        ct++;
        i--;
       }
       return ct;
    }
};