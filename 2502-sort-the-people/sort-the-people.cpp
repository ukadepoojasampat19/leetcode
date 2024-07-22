class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp;
        vector<string> result;
        for(int i=0;i<names.size();i++)
        {
            mp[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end());
        for(int i=0;i<heights.size();i++)
        {
            if(mp.find(heights[i]) != mp.end())
            {
                result.push_back(mp[heights[i]]);
            }
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};