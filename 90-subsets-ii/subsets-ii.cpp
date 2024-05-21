class Solution {
public:
    void sunset(vector<int>& nums,vector<int>& temp,int idx,set<vector<int>>& result)
    {
        if(idx == nums.size())
        {
            result.insert(temp);
            return;
        }

        sunset(nums,temp,idx +1,result);
        temp.push_back(nums[idx]);
        sunset(nums,temp,idx +1,result);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> temp;
        set<vector<int>> result;
        sort(nums.begin(),nums.end());
        sunset(nums,temp,0,result);

        vector<vector<int>> res(result.begin(),result.end());

        return res;
    }
};