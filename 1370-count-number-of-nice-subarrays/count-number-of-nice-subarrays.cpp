class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    int atMost(vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int result = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1) {
                --k;
            }
            while (k < 0) {
                if (nums[left] % 2 == 1) {
                    ++k;
                }
                ++left;
            }
            result += (right - left + 1);
        }
        return result;
    }
};
