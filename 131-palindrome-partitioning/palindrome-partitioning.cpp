class Solution {
public:
    bool idPlindrome(string s, int l,int r)
    {
        while(l < r)
        {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string& s,int idx,vector<string> curr,vector<vector<string>>& result)
    {
        if(idx == s.length())
        {
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<s.length();i++)
        {
            if(idPlindrome(s,idx,i))
            {
                curr.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,curr,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> result;

        backtrack(s,0,curr,result);
        return result;
        
    }
};