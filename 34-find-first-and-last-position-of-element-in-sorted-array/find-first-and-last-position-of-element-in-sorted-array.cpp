class Solution {
public:
    void first_occur(int l,int h,vector<int>& nums,int target,int& first_occ){
        while( l<=h){
            int m = (l+h)/2;

            if(nums[m] == target){
                first_occ = m;
                h=m-1;
            }else if(nums[m] < target){
                l=m+1;
            }else{
                h = m-1;
            }
        }
      }
      void last_occur(int l,int h,vector<int>& nums,int target,int& last_occ){
        while( l<=h){
            int m = (l+h)/2;

            if(nums[m] == target){
                last_occ = m;
                l= m+1;
            }else if(nums[m] < target){
                l=m+1;
            }else{
                h = m-1;
            }
        }
      }
    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
      int l=0;
      int first_occ = -1;
      int last_occ = -1;
      int h=n-1;

      first_occur(l,h,nums,target,first_occ);
      last_occur(l,h,nums,target,last_occ);

      return {first_occ,last_occ};
    }
};