class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }
        unordered_map<char,int> first;
        unordered_map<char,int> second;
        for(int i=0;i<s.length();i++)
        {
            first[s[i]]++;
            second[t[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(second.find(s[i]) != second.end())
            {
                if(first[s[i]] == second[s[i]])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};