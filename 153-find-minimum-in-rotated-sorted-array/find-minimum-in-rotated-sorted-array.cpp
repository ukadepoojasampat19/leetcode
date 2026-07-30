class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int h = n-1;
        int min_ele = INT_MAX;

        while(l <= h){
            int m = (l+h)/2;

            min_ele = min(min_ele, nums[m]);
            if(nums[l] > min_ele && nums[h] > min_ele){
                l++;
                h--;
                continue;
            }
          if(nums[l] <= min_ele  && nums[h] < min_ele){
            int min_value = min(nums[l], nums[h]);

            if(min_value ==  nums[l]){
                h=m-1;
            }else{
                l = m+1;
            }
          }else if(nums[l] <=min_ele){
            h = m-1;
          }else{
            l=m+1;
          }
        }
        return min_ele;
    }
};