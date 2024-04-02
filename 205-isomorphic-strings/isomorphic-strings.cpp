class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }
        unordered_map<char,char> str1;
        unordered_map<char,char> str2;

        for(int i=0; i< s.length(); i++)
        {
            char s_char=s[i];
            char t_char=t[i];

            if(str1.find(s_char) == str1.end())
            {
                str1[s_char]= t_char;
            }
            else
            {
                if(str1[s_char] != t_char)
                {
                    return false;
                }
            }

            //check for t to s

            if(str2.find(t_char) == str2.end())
            {
                str2[t_char] = s_char;
            }
            else
            {
                if(str2[t_char] != s_char)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};