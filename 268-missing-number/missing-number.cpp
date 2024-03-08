class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> check;
        int s=nums.size();
        sort(nums.begin(),nums.end());
        int max=nums[s-1];
        for(auto n: nums)
        {
            check[n]=1;
        }
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