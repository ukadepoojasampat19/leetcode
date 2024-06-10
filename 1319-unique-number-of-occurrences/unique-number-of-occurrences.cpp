class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> uni;
        for(auto &n : arr)
        {
            mp[n]++;
        }
        for(auto &n : mp)
        {
            if(uni.find(n.second) != uni.end())
            {
                return false;
            }
            uni.insert(n.second);
        }
        return true;
    }
};