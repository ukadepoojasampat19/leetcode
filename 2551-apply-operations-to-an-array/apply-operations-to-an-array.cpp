class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for(int i=0;i<(n-1);i++)
        {
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }
       int ct=0;
        for(int j=0;j<n;j++){
            if(nums[j] != 0){
                res[ct] = nums[j];
                ct++;
            }
        }
        return res;
        
    }
};