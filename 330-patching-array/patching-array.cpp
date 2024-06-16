class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch =0;
        long max_len =0;
        int i=0;
        while(max_len < n)
        {
            if(i < nums.size() && nums[i] <= max_len+1)
            {
                max_len += nums[i];
                i++;
            } 
                
            else
            {
                max_len += max_len +1;
                patch++;
            }
        }
        return patch;
    }
};