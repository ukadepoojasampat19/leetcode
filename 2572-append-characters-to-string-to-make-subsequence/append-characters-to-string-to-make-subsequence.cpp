class Solution {
public:
    int appendCharacters(string s, string t) {

        int s_len=s.length();
        int t_len=t.length();
        
         int j =0;
        for(int i=0;i<s_len && j<t_len;i++)
        {
            if(t[j] == s[i])
            {
                j++;
            }
        }
      return t_len -j;
    }
};