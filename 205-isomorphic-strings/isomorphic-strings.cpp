class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.length() != t.length())
        {
            return false;
        }
        /*unordered_map<char,char> str1;
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
        return true;*/
       /* unordered_map<char,char> map_char;
        unordered_set<char> set_vals;

        for(int i=0;i<s.length();i++)
        {
            if(map_char.find(s[i]) != map_char.end())
            {
                 if(map_char[s[i]] != t[i])
                 {
                    return false;
                 }
            }
            else
            {
                if(set_vals.find(t[i]) != set_vals.end())
                {
                    return false;
                }
                map_char[s[i]]=t[i];
                set_vals.insert(t[i]);
            }
        }

        return true;*/
         map<char, char> m1, m2;
    for (int i = 0; i < s.size(); ++i) {
        if ((m1[s[i]] && m1[s[i]] != t[i]) || (m2[t[i]] && m2[t[i]] != s[i])) return false;
        m1[s[i]] = t[i];
        m2[t[i]] = s[i];
    }
        return true;
    }
};