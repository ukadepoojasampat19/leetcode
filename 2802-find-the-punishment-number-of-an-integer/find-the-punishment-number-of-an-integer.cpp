class Solution {
public:
    bool canPartition(string s, int target, int start) {
        if (start == s.length()) return target == 0;
        
        int sum = 0;
        for (int i = start; i < s.length(); i++) {
            sum = sum * 10 + (s[i] - '0'); // Forming numbers from substrings
            if (sum > target) break; // No need to proceed further
            if (canPartition(s, target - sum, i + 1)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string s = to_string(square);
            if (canPartition(s, i, 0)) {
                ans += square;
            }
        }
        return ans;
    }
};
