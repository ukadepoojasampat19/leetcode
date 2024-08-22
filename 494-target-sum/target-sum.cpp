class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the target is out of the possible range, return 0
        if (target > totalSum || target < -totalSum) {
            return 0;
        }
        
        // DP table: offset by totalSum to handle negative sums (sum ranges from -totalSum to totalSum)
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * totalSum + 1, 0));
        
        // Base case: one way to achieve a sum of 0 with no elements
        dp[0][totalSum] = 1;
        
        for (int i = 1; i <= nums.size(); i++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[i - 1][sum + totalSum] > 0) {
                    dp[i][sum + nums[i - 1] + totalSum] += dp[i - 1][sum + totalSum];
                    dp[i][sum - nums[i - 1] + totalSum] += dp[i - 1][sum + totalSum];
                }
            }
        }
        
        return dp[nums.size()][target + totalSum];
    }
};
