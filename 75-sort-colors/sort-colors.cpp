class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for(auto &n: nums)
        {
            mp[n]++;
        }
        int i=0;
        for(auto &n: mp)
        {
            int num=n.second;
            while(num--)
            {
                nums[i] = n.first;
                i++;
            }
        }
        
    }
};