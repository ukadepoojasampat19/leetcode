class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // Map to track frequency of characters
        int l = 0, r = 0;
        int ct = 0; // Initialize to 0 to handle cases when the string is empty
        
        while (r < s.length()) {
            mp[s[r]]++; // Increment the frequency of the character at `r`
            
            // If the character repeats (i.e., its count is greater than 1)
            while (mp[s[r]] > 1) {
                mp[s[l]]--; // Decrease the frequency of the character at `l`
                l++; // Move the left pointer to shrink the window
            }
            
            // Update the length of the longest substring without repeating characters
            ct = max(ct, r - l + 1);
            
            r++; // Expand the window by moving the right pointer
        }
        
        return ct;
    }
};
