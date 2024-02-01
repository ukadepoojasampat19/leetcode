class Solution {
public:
    void solve(vector<int>& nums,vector<int>& currSubset,int index,vector<vector<int>>& result)
    {
       if(index == nums.size())
       {
           result.push_back(currSubset);
           return;
       }
        
        solve(nums,currSubset,index + 1,result);
        
        currSubset.push_back(nums[index]);
        solve(nums,currSubset,index+1,result);
        
        currSubset.pop_back(); //backtrack
       
        
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSubset;
        vector<vector<int>> result;
        
        solve(nums,currSubset,0,result);
         return result;
    }
};