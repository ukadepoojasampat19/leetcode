class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        
        int odd_num =0;
        mp[odd_num]++;
        int n = nums.size();
        int result =0;
        for(int i=0;i<n;i++)
        {
            odd_num += (nums[i]%2);

            if(mp.count(odd_num -k))
            {
                result += mp[odd_num -k];
            }

            mp[odd_num]++;
        }
        return result;
    }
};