class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> str1;
        unordered_map<char , char> str2;

        if(s.length() != t.length()) return false;

        for(int i=0;i<s.length();i++)
        {
            char num1 = s[i];
            char num2 = t[i];
            
            //check for s to t
            if(str1.find(s[i]) != str1.end())
            {
                if(str1[num1] != num2) return false;
            }
            else
            {
                str1[num1] =  num2;    
            }

            //check for t to s
            if(str2.find(t[i]) != str2.end())
            {
                if(str2[num2] != num1) return false;
            }
            else
            {
                str2[num2] =  num1;    
            }
        }
        return true;
        
    }
};