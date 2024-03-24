class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            //already visited
            if(nums[index]<0){
                ans=index;
                break;
            }
            //visited mark
            nums[index]*=-1;
        }
        return ans;
        
    }
};