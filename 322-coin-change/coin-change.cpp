#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX

class Solution {
public:
    int solve(std::vector<int>& coins, int amount, int n,vector<vector<int>>& dp) {
        // Base cases
        if (amount == 0) return 0; // No coins are needed to make amount 0
        if (n <= 0) return INT_MAX; // If no coins left and amount is not 0
        if (amount < 0) return INT_MAX; // Invalid scenario where amount becomes negative
        if(dp[n][amount] != -1) return dp[n][amount];
        // Include the current coin and check remaining amount
        int include = solve(coins, amount - coins[n-1], n,dp);
        if (include != INT_MAX) include += 1; // Include the current coin

        // Exclude the current coin and move to the next
        int exclude = solve(coins, amount, n-1,dp);

        // Return the minimum of including or excluding the current coin

        dp[n][amount] = min(include, exclude);
        return dp[n][amount];
    }

    int coinChange(std::vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int result = solve(coins, amount, coins.size(),dp);
        // If result is INT_MAX, it means we couldn't find a solution
        return result == INT_MAX ? -1 : result;
    }
};
