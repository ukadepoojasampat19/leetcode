class Solution {
public:
int bti(vector<int> v)
{
    int ans=0;
    for(int i=0;i<32;i++)
    {
        if(v[i])
        {
            ans += (1<<i); /* 2 raised to i*/
        }
    }
    return ans;
}
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        vector<int> v(32);
        int l=0;
        int ans = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<32;j++)
            {
                if((1<<j)&nums[i])
                {
                    v[j]++;
                }
            }


            int p =bti(v);
            while(l<=i && p>=k)
            {
                ans= min(ans,i-l+1);
                for(int j=0;j<32;j++)
                {
                    if((1<<j)&nums[l])
                    {
                        v[j]--;
                    }
                    
                }
                p =bti(v);
                l++;
            }
        }

        return (ans == INT_MAX)? -1 : ans;
    }
};