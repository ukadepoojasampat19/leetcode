#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        // Find the maximum value in nums to determine the size of the frequency array
        int maxValue = *max_element(nums.begin(), nums.end());

        // Create a frequency array to count the occurrences of each number
        std::vector<int> freq(maxValue + nums.size(), 0);
        for (int num : nums) {
            freq[num]++;
        }

        int moves = 0;
        int taken = 0;

        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] > 1) {
                taken += freq[i] - 1;
                moves -= (freq[i] - 1) * i;
            } else if (freq[i] == 0 && taken > 0) {
                taken--;
                moves += i;
            }
        }

        return moves;
    }
};
