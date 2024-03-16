class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        
        for (char ch : s)
            counts[ch]++;
        
        int length = 0;
        bool hasOdd = false;
        
        for (auto& p : counts) {
            length += p.second / 2 * 2; // add even count of characters
            if (p.second % 2 == 1)
                hasOdd = true; // flag that there is at least one odd count character
        }
        
        // If there was at least one character with an odd count, add 1 to the length
        if (hasOdd)
            length++;
        
        return length;
    }
};