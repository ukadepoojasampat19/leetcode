class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto& n: nums)
        {
            mp[n]++;
        }

        for(auto& n: mp)
        {
            if(n.second == 1)
            {
                res.push_back(n.first);
            }
        }
        return res;
    }
};