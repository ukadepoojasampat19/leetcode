class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
               vector<int> result;

        // Iterate through the array and mark visited elements
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Get the index to mark

            // Mark the element at index as visited
            nums[index] = -abs(nums[index]); // Negate to mark visited
        }

        // Find the indices with non-negative values
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                // Add the missing numbers (indices + 1) to the result
                result.push_back(i + 1);
            }
        }

        return result;
        }
};