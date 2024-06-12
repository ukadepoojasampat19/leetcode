class Solution {
public:
    void sortColors(vector<int>& nums) {
       /* map<int, int> mp;
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
        }*/

        int n = nums.size();
        int i=0; // denote 0
        int j=0; //denote 1
        int k=n-1; // denote 2

        while(j <= k)
        {
            if(nums[j] == 0)
            {
                swap(nums[j],nums[i]);
                j++;
                i++;

            }
            else if(nums[j] == 1)
            {
                j++;
            }
            else
            {
                swap(nums[j],nums[k]);
                k--;
            }
        }
        
    }
};