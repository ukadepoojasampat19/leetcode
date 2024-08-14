class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> res;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                res.push_back(abs(nums[i]-nums[j]));
            }
        }
        nth_element(res.begin(),res.begin()+(k-1),res.end());
        return res[k-1];
    }
};