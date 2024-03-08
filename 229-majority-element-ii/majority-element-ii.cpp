class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int> res;
         vector<int> result;
        for(auto n: nums)
        {
            res[n]++;

            if(res[n] > (nums.size() / 3))
            {
                if(find(result.begin(),result.end(),n) == result.end())
                {
                    result.push_back(n);
                }
                
            }
        }
        return result;
    }
};