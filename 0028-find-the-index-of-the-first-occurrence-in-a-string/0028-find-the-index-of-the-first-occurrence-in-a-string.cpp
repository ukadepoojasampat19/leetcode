class Solution {
public:
    int strStr(string h, string t) {
       /* bool count=0;
         for(int i=0;i<haystack.size();i++)
         {
             int j = 0;
             for(j; j<needle.length();j++)
             {
                 
                 if(haystack[i+j] != needle[j])
                 {
                     break;
                 }                    
               
             }
             if(j==needle.length())
             {
                 return i;
             }
         }
        return -1;*/
        
        int k = t.length();
        for(int i = 0 ; i <= h.length() ; i++){
            string temp = h.substr(i,k);
            if(temp == t) return i;
        }
        return -1;
    }
};