class Solution {
public:
    void recur(vector<int>& candidates, int target, int idx, int sum, vector<vector<int>>& result, vector<int>& temp) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (sum > target || idx == candidates.size()) return;

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            temp.push_back(candidates[i]);
            recur(candidates, target, i + 1, sum + candidates[i], result, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        recur(candidates, target, 0, 0, result, temp);
        return result;
    }
};
