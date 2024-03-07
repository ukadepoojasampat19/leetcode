class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(result.find(nums[i]) == result.end())
            {
                result[nums[i]]=1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};