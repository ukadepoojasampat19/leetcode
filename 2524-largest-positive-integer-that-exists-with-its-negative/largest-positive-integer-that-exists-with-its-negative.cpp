class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       /* int l=0;
        int r=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i] == -(nums[j]))
                {
                    return nums[j];
                }
            }
        }*/

        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i] >0 && binary_search(nums.begin(),nums.end(),-nums[i]))
            {
                return nums[i];
            }
        }
        return -1;
    }
};