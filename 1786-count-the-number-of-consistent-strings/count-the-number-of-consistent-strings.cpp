class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_map<int,int> mp;
        int ct=0;
        for(auto& n: allowed)
        {
            mp[n]++;
        }

        for(auto& n: words)
        {
            string temp = n;
            bool check=true;
            for(auto& m: temp)
            {
                if(!mp.count(m))
                {
                    check = false;
                    break;
                }
            }
            if(check) ct++;
        }
        return ct;
    }
};