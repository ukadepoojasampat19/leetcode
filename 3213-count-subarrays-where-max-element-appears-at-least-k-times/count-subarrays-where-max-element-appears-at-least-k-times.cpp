class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       long long mx= *max_element(nums.begin(),nums.end());
       long long ct=0,ans=0;
       int l=0,r=0;
       while(r < nums.size())
       {
            if(nums[r] == mx) ct++;

            while(ct >=k)
            {
                if(nums[l] == mx)ct--;
                l++;
                ans+= nums.size() - r;
            }
            r++;
       }
       return ans;
    }
};