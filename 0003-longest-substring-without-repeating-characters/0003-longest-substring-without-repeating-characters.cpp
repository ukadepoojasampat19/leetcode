class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
      map<char,int> result;
        int maxlen=0;
        int start=-1;
        
        for(int i=0;i<s.length();i++)
        {
            if(result.find(s[i]) != result.end() && result[s[i]] > start)
            {
                start= result[s[i]];
            }
            result[s[i]]=i;
            maxlen= max(maxlen,i - start);
        }  
        
        return maxlen;
    }
};