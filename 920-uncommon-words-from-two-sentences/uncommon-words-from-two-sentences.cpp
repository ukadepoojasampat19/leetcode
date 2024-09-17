class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> str1;
        vector<string> str2;
        unordered_map<string,int> mp;
       
        vector<string> result;

        string temp;
        stringstream ss1(s1);

        while(ss1 >> temp)
        {
            str1.push_back(temp);
        }
        stringstream ss2(s2);
        temp="";
         while(ss2 >> temp)
        {
            str2.push_back(temp);
        }
        
        for(auto& n: str1)
        {
            mp[n]++;
        }
        for(auto& n: str2)
        {
            mp[n]++;
        }
        for(auto& n: mp)
        {
            int m = n.second;
            if(m == 1)
            {
                result.push_back(n.first);
            }
        }
        return result;
    }
};