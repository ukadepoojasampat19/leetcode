class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.length();
        string result;

        // Ensure that the string length is a multiple of k
        if (n % k != 0) {
            return "Invalid input: n must be a multiple of k.";
        }

        // Iterate over the string in steps of k to create substrings
        for (int i = 0; i < n; i += k) {
            string sub = s.substr(i, k);
            int sum = 0;

            // Calculate the sum of hash values for the substring
            for (char c : sub) {
                sum += c - 'a';  // Convert character to 0-indexed position in the alphabet
            }

            // Find the corresponding character for the remainder when divided by 26
            int hashedChar = sum % 26;
            result += (hashedChar + 'a');  // Convert back to character and append to result
        }

        return result;
    }
};
