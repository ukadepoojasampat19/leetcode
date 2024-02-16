class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        map<int, bool> mp;
        for(int i=0;i<nums.size();i++)
        {
            //check if the element is present in the map or not 
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = true;
                temp.push_back(nums[i]);
            }
        }
        nums=temp;
        
        return temp.size();
        
    }
};