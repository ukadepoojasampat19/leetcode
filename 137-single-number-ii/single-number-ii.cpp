class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /* FIRST APPROACH 
        unordered_map<int,int> freq;
        for(auto &n: nums)
        {
            freq[n]++;
        }
        for(auto &pair: freq)
        {
            if(pair.second == 1)
            {
                return pair.first;
            }
        }
        return 0;*/
       //bit manipulation
       int result = 0;
        for (int k_bit = 0; k_bit < 32; k_bit++) {
            int mask = 1 << k_bit;
            int count_ones = 0;
            for (auto& n : nums) {
                if (n & mask) { // Check if the k_bit is set in the current number
                    count_ones++;
                }
            }
            if (count_ones % 3 != 0) { // If count_ones is not a multiple of 3, set the corresponding bit in result
                result |= mask;
            }
        }
        return result;
    }
};