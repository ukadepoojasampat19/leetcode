class Solution {
public:
    int recurr(int idx,vector<int>& nums,int target,int sum)
    {
            if(idx == nums.size())
            {
                if(sum == target)
                {
                    return 1;
                }
                return 0;
            }
           // if(sum > target) return 0;
           // sum += nums[idx];
            int l =  recurr(idx+1,nums,target,sum + nums[idx]);
           // sum -= nums[idx];
            int r =  recurr(idx+1,nums,target,sum - nums[idx]);

            return l+r;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return recurr(0,nums,target,0);
        
    }
};