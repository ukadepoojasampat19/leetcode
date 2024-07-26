class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> str1;
        unordered_map<char,int> str2;
        for(int i=0;i<s.length();i++)
        {
            str1[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            str2[t[i]]++;
        }

       for(auto& n: str1)
       {
            char ch = n.first;
            int freq = n.second;
            if(str2.find(ch) != str2.end())
            {
                if(str2[ch] != freq) return false;
            }
            else
            {
                return false;
            }
       }
       return true;
    }
};