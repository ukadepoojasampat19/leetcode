class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> check(nums.begin(), nums.end());
        int s=nums.size();
       
       
       
        for(int i=0;i<=s;i++)
        {
            if(check.find(i) == check.end())
            {
                return i;     
            }
            }
        return -1;
    }
};