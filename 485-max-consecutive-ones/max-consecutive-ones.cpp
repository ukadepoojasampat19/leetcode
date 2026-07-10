class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count =INT_MIN;
        int ct =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 1) ct= ct+1;
            else{
                max_count = max(max_count,ct);
                ct =0;
            }
        }
         max_count = max(max_count,ct);
            
        return max_count;
    }
};