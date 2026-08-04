class Solution {
public:
    void getCombination(int idx, vector<int>& candidates,int target,vector<int> res,int n, vector<vector<int>>& ans){

        //base condition
      
        if(idx == n){
            if(target == 0){
                ans.push_back(res);
            }
            return;
        }

        if(candidates[idx] <= target){
       
        res.push_back(candidates[idx]);
        getCombination(idx,candidates,target-candidates[idx],res,n,ans);
           res.pop_back();
        }
       
        getCombination(idx+1,candidates,target,res,n,ans);
      
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int n = candidates.size();
        int idx =0;

        getCombination(idx,candidates,target,res,n,ans);
        return ans;
    }
};