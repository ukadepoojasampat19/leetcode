class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size();
        int c = points[0].size();
        
        vector<long long> dp(c, 0);
        
        // Initialize dp with the first row values
        for(int j = 0; j < c; j++) {
            dp[j] = points[0][j];
        }
        
        // Process each row from the second row onwards
        for(int i = 1; i < r; i++) {
            vector<long long> left(c, 0);
            vector<long long> right(c, 0);
            vector<long long> temp(c, 0);

            // Fill the left array
            left[0] = dp[0];
            for(int j = 1; j < c; j++) {
                left[j] = max(left[j-1] - 1, dp[j]);
            }

            // Fill the right array
            right[c-1] = dp[c-1];
            for(int j = c - 2; j >= 0; j--) {
                right[j] = max(right[j+1] - 1, dp[j]);
            }

            // Calculate maximum points for each column in the current row
            for(int j = 0; j < c; j++) {
                temp[j] = points[i][j] + max(left[j], right[j]);
            }
            
            dp = temp;
        }

        // Return the maximum points possible
        return *max_element(dp.begin(), dp.end());
    }
};
