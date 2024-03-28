class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        int mx=INT_MIN,st=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            temp[nums[i]]++;
            if(temp[nums[i]] > k)
            {
                while(temp[nums[i]] > k)
                {
                     temp[nums[st]]--;
                     st++;
                }
               
            }
            mx=max(mx,i-st+1);
        }
        return mx;
    }
};