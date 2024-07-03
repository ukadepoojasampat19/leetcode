#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;  // If there are 4 or fewer elements, we can change all of them to the same value.

        sort(nums.begin(), nums.end());

        // We will consider four cases:
        // 1. Change the three largest elements
        // 2. Change the two largest elements and the smallest element
        // 3. Change the largest element and the two smallest elements
        // 4. Change the three smallest elements
        int result = INT_MAX;
        result = min(result, nums[n - 1] - nums[3]);
        result = min(result, nums[n - 2] - nums[2]);
        result = min(result, nums[n - 3] - nums[1]);
        result = min(result, nums[n - 4] - nums[0]);

        return result;
    }
};
