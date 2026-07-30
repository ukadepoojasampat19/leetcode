class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int h = n-1;
        int min_ele = INT_MAX;

        while(l <= h){
            int m = (l+h)/2;

           if(nums[l] <= nums[m]){
             min_ele = min(min_ele, nums[l]);
             l=m+1;
           }else{
            min_ele= min(min_ele, nums[m]);
            h=m-1;
           }
        }
        return min_ele;
    }
};