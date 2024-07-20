class Solution {
public:
    int minimumLength(string s) {
        vector<int> vec(26, 0); // Initialize a vector to count frequency of each character
        int res = 0;

        // Count the frequency of each character in the string
        for (char ch : s) {
            vec[ch - 'a']++;
        }

        // Calculate the result based on the frequency of each character
        for (int cnt : vec) {
            if (cnt <= 2) {
                res += cnt;
            } else {
                if (cnt % 2 == 1) {
                    res++;
                } else {
                    res += 2;
                }
            }
        }

        return res;
    }
};
