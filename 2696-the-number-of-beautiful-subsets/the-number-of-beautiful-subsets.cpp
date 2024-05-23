class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, int& result, int idx, int k) {
        if (idx == nums.size()) {
            if (!curr.empty()) {
                result++;
            }
            return;
        }

        // Case 1: Do not include nums[idx] in the current subset
        backtrack(nums, curr, result, idx + 1, k);

        // Case 2: Include nums[idx] in the current subset
        bool canInclude = true;
        for (int num : curr) {
            if (abs(num - nums[idx]) == k) {
                canInclude = false;
                break;
            }
        }
        
        if (canInclude) {
            curr.push_back(nums[idx]);
            backtrack(nums, curr, result, idx + 1, k);
            curr.pop_back();
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> curr;
        int result = 0;
        backtrack(nums, curr, result, 0, k);
        return result;
    }
};
