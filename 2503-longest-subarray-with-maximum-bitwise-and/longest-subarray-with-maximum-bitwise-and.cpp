class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int max_value = *max_element(nums.begin(),nums.end());

        int longest=0;
        int current =0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == max_value)
            {
                current++;
            }
            else
            {
                longest = max(longest, current);
                current =0;
            }
        }
        longest = max(longest, current);
        return longest;
    }
};