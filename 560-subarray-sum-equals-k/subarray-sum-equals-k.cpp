class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, int> mp;
        int sum=0;
        mp.insert({0,1});
        int result=0;

        for(int i=0;i< n;i++)
        {
            sum += nums[i];
            int curr_val = sum - k;

            if(mp.find(curr_val) != mp.end())
            {
                result += mp[curr_val];
                //mp[curr_val]++;
            }
          
            mp[sum]++;
            
        }

        return result;
        
    }
};