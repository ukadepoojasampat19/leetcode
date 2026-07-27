class Solution {
public:
  void lower_Bound(int& min_idx,int l,int h,int mid,int target,vector<int> nums){
        if(l > h) return;
         mid = (l+h)/2;
         if(nums[mid] >=  target){
                min_idx =  min(min_idx,mid);    
                lower_Bound(min_idx,l,mid-1,mid,target, nums);
            }else{
                  lower_Bound(min_idx,mid +1,h,mid,target, nums);
            }

    }
    int searchInsert(vector<int>& nums, int target) {
       int n = nums.size();
        int min_idx = n;
        int l = 0;
        int h = n-1;
        int mid;

        lower_Bound(min_idx,l,h,mid,target, nums);
        
        return min_idx;
    }
};