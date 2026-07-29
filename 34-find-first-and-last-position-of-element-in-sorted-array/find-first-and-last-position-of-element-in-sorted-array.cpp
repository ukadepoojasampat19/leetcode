class Solution {
public:
 int lowerBound(vector<int> &nums, int x){
     int n = nums.size();
     int l=0;
     int h = n-1;
     int m;
    int ans = n;
     while(l <= h){
        m = (l+h)/2;

        if(nums[m] >= x){
            ans = m;
            h=m-1;
        }else{
            l=m+1;
        }

     }
     return ans;
    }
    int upperBound(vector<int> &nums, int x){
     int n = nums.size();
     int l=0;
     int h = n-1;
     int m;
    int ans = n;
     while(l <= h){
        m = (l+h)/2;

        if(nums[m] > x){
            ans = m;
            h=m-1;
        }else{
            l=m+1;
        }

     }
     return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target);

        if(lb == n || nums[lb] != target){
            return {-1,-1};
        }
         
        
       
       return {lb, upperBound(nums, target) -1};
    }
};