class Solution {
public:
    int recurr(int idx, vector<int>& nums, int sum, int target, vector<vector<int>>& dp) {
        // Base case: if we have considered all numbers
        if (idx == nums.size()) {
            // If the sum equals the target, we found a valid expression
            return sum == target ? 1 : 0;
        }

        // Check if the result is already computed
        if (dp[idx][sum + 1000] != -1) { // We use +1000 to handle negative sums
            return dp[idx][sum + 1000];
        }

        // Try adding the current number
        int add = recurr(idx + 1, nums, sum + nums[idx], target, dp);
        
        // Try subtracting the current number
        int subtract = recurr(idx + 1, nums, sum - nums[idx], target, dp);

        // Store the result in the DP table and return it
        return dp[idx][sum + 1000] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // DP table: offset by 1000 to handle negative sums (since sum can range from -1000 to +1000)
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return recurr(0, nums, 0, target, dp);
    }
};
