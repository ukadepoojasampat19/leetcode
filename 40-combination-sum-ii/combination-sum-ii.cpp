class Solution {
public:
    void getCombinationSum2(int idx,vector<int>& candidates,int target,vector<int>& res,   vector<vector<int>>& ans){
                if(target == 0){
                    ans.push_back(res);
                    return;
                }

                for(int i=idx;i<candidates.size();i++){
                    if(i > idx && candidates[i] == candidates[i-1]) continue;
                    if(candidates[i] > target) break;

                    res.push_back(candidates[i]);
            getCombinationSum2(i +1,candidates,target -candidates[i] ,res,ans);
                    res.pop_back();
                }
    

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;

        getCombinationSum2(0,candidates,target,res,ans);
        return ans;
    }
};