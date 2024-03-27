class Solution {
public:
   
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // No subarray can have a product less than or equal to 0 or 1
        
        int count = 0;
        int product = 1;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1); // Number of subarrays ending at right
        }

        return count;

    }
};