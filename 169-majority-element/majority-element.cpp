class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> majority;
        for(auto n : nums)
        {
            majority[n]++;

            if(majority[n] > nums.size() /2)
            {
                return n;
            }
        }
        
        
     return -1;  
    }
};