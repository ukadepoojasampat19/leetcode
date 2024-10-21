class Solution {
public:
    int backtrack(string s,int st, unordered_set<string>& seen)
    {
        if(st == s.length()) 
        {
            return 0;
        }

        int count=0;
        string current="";

        for(int i=st;i<s.length();i++)
        {
            current += s[i];
            if(seen.find(current) == seen.end())
            {
                seen.insert(current);
                count = max(count, 1+ backtrack(s,i+1,seen));
                seen.erase(current);
            }
        }

        return count;
       

    }
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s,0,seen);
        
    }
};