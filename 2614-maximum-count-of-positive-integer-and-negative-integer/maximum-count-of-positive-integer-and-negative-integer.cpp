class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos_ct=0;
        int net_ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                net_ct++;
            }
            else if(nums[i] > 0){
                pos_ct++;
            }
        }
        return max(net_ct,pos_ct);
    }
};