class Solution {
public:
void  backtrack(vector<int>& candidates,int target, vector<vector<int>>& result,vector<int>& curr,int st)
{
    if(target == 0)
    {
        result.push_back(curr);
        return;
    }
    for(int i=st;i< candidates.size() && candidates[i] <= target ;i++)
    {
        curr.push_back(candidates[i]);
        backtrack(candidates,target -candidates[i],result,curr,i);
        curr.pop_back();
        

    }
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,result,curr,0);
        return result;
        
    }
};