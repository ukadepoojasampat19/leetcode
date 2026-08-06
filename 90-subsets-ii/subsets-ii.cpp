class Solution {
public:
     void getCombinationSum2(int idx,vector<int>& nums,vector<int>& res,   vector<vector<int>>& ans){
              
                    ans.push_back(res);


                for(int i=idx;i<nums.size();i++){
                    if(i > idx && nums[i] == nums[i-1]) continue;


                    res.push_back(nums[i]);
            getCombinationSum2(i +1,nums,res,ans);
                    res.pop_back();
                }
    

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;

        getCombinationSum2(0,nums,res,ans);
        return ans;
    }
};