class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        //brute force approach 
        /*int n = nums.size();
        int ct=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum += nums[j];
                if(sum % k == 0)
                {
                    ct++;
                }

            }
        }
        return ct;*/

        int n = nums.size();
        unordered_map<int, int> mp;
        int sum=0;
        int result=0;
        mp.insert({0,1});

        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            int rem = sum % k;

            if( rem < 0)
            {
                 rem += k;
            }
            if(mp.find(rem) != mp.end())
            {
                result += mp[rem];
            }
            mp[rem]++;
        }
        return result;
        }
};