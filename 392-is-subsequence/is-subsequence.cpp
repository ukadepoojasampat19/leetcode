class Solution {
public:
    bool isSubsequence(string s, string t) {
       /* int j=0;
        bool check=false;
        for(int i =0;i<t.length();i++)
        {
            if(s[j] == t[i])
            {
                j++;
                

            }
        }
        if(j == s.length())
        {
            return true;
        }
        return false;*/
        int sp=0;
        int tp=0;
        while(sp < s.length() && tp < t.length())
        {
            if(s[sp] == t[tp])
            {
                sp++;
            }
            tp++;
        }

        return sp == s.length();
    }
};