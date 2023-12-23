class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        unordered_map <int, int> mp;
       
        
        for(int j=0;j<nums.size();j++)
        {
            int num=target - nums[j];
            
            if(mp.find(num) != mp.end() )
            {
                return {mp[num], j};
            }
            
            mp[nums[j]]=j;
        }
        
        return {};
         
        
    }        
    
};