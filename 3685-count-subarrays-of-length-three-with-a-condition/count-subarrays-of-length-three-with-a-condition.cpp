class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ct=0;
        for(int i=1;i<nums.size() -1;i++){
           if(nums[i] == (nums[i-1] + nums[i+1]) * 2){
            ct++;
           }
        }
        return ct;
    }
};