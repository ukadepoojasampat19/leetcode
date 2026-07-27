class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l =0;
        int h = n-1;
        int mid =0;

        while(l <= h){
            mid = (l+h) / 2;

            if(nums[mid] ==  target){
                return mid;
            }else if(target > nums[mid]){
                l = mid+1;
            }else{
                h = mid -1;
            }
        }
        return -1;
    }
};