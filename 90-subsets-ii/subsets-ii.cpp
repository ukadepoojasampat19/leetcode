class Solution {
public:
    void  getAllSubset(int idx,vector<int>& nums, vector<vector<int>>& ans,vector<int>& curr){

            if(idx == nums.size()){
                if (find(ans.begin(), ans.end(), curr) == ans.end()){
                      ans.push_back(curr);
                }
              
                return;
            }


        curr.push_back(nums[idx]);
        getAllSubset(idx + 1,nums,ans,curr);
        curr.pop_back();
        getAllSubset(idx + 1,nums,ans,curr);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<vector<int>> ans;
          vector<int> curr;
          sort(nums.begin(),nums.end());

          getAllSubset(0,nums,ans,curr);
          return ans;
    }
};