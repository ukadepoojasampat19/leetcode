class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> result;
        vector<int> temp;
        for(auto n: nums)
        {
            result[n]++;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(!result.count(i))
            {
                temp.push_back(i);
            }
        }
        return temp;
    }
};