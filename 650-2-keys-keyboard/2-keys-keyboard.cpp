class Solution {
public:
    int minSteps(int n) {
           if (n == 1) return 0;

    std::vector<int> dp(n + 1, 0);
    
    for (int i = 2; i <= n; i++) {
        dp[i] = i;  // Initialize with the maximum possible operations (all paste)
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                dp[i] = dp[j] + dp[i / j];
                break;
            }
        }
    }
    
    return dp[n];
    }
};