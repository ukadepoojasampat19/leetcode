class Solution {
public:
    int specialArray(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(auto& n: nums)
        {
            mp[n]++;
        }
        int maxnum = *max_element(nums.begin(),nums.end());
        for(int x=0;x<= maxnum;x++)
        {
            int count=0;
            
            for(auto& [num,ct]: mp)
            {
                if(num >=x)
                {
                    count+=ct;
                }
            }
            if(count == x)
            {
                return count;
            }


        }
        return -1;
        
    }
};