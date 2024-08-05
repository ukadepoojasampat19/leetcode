class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int curr_sum =0;
        for(auto& n: nums)
        {
            curr_sum += n;
        }

        if(curr_sum % 2 != 0) return false;
        int target = curr_sum / 2;

        //TABULATION APPROACH
        /*
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1,0));

        dp[0][0] = true;

        for(int i=1;i<=nums.size();i++)
        {
            for(int j=0;j<=target;j++)
            {
                    //not include
                    dp[i][j] = dp[i-1][j];

                    //include;
                    if(nums[i-1]  <= j)
                    {
                        dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                    }
            }
        }
        return dp[nums.size()][target];*/

        //MEMOIZATION APPROACH IN TABLE
        vector<bool> dp(target+1,false);
        dp[0]= true;

        for(auto& n: nums)
        {
            for(int j=target; j>=n; j--)
            {
                dp[j] = dp[j] || dp[j - n];
            }
        }
        return dp[target];
    }
};