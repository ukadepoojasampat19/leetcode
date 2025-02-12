#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // Function to calculate the sum of digits of a number
    int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int max_sum = -1;  // Initialize with -1 as per problem constraints
        map<int, int> max_s;  // Use map to store sum of digits → max number

        for (int i = 0; i < nums.size(); i++) {
            int sum_digit = sumOfDigits(nums[i]);

            // If sum of digits is already present in map
            if (max_s.find(sum_digit) != max_s.end()) {
                max_sum = max(max_sum, nums[i] + max_s[sum_digit]);
                max_s[sum_digit] = max(nums[i], max_s[sum_digit]);  // Store the max number for that sum of digits
            } else {
                max_s[sum_digit] = nums[i];  // Store the number if sum of digits is not found
            }
        }
        return max_sum;
    }
};
