class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // optimize solution with space complexity = o(1);
        int n = nums.size();
        vector<int> ans(n);

        

        // prefix calculation 
        ans[0] = 1;
        for(int i =1;i<n;i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        // suffix calculation 

        int rightpt = 1;
        for(int i =n-1;i>=0;i--){
            ans[i] = ans[i] * rightpt;
            rightpt *= nums[i];
        }

      

        return ans;
    }
};