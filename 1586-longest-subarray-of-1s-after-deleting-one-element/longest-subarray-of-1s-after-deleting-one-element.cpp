class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int max_num = 0;
        int ct_z = 0;
        
        // Sliding window approach
        while (r < nums.size()) {
            if (nums[r] == 0) {
                ct_z++;
            }
            
            while (ct_z > 1) {
                if (nums[l] == 0) {
                    ct_z--;
                }
                l++;
            }
            
            max_num = max(max_num, r - l);
            r++;
        }
        
        return max_num;
    }
};
