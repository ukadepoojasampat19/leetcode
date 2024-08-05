class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int curr_sum = 0;
        
        // Calculate the total sum
        for (int num : nums) {
            curr_sum += num;
        }
        
        // If the total sum is odd, it can't be partitioned into two equal subsets
        if (curr_sum % 2 != 0) {
            return false;
        }
        
        int target = curr_sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: A sum of 0 is always achievable
        
        for (int num : nums) {
            // Traverse dp array from right to left
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};
