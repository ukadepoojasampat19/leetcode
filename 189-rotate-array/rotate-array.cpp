class Solution {
public:
    void rotate(vector<int>& nums, int k) {
     // int n = nums.size();

     // vector<int> res(n);
      // k = k % n;
      //for(int i=0;i<n;i++){
        //res[(i + k) % n] = nums[i];
     
   //   }
    //  nums = res;
    //space optimatization 
     int n = nums.size();
     k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin()+ k, nums.end());
    }
};