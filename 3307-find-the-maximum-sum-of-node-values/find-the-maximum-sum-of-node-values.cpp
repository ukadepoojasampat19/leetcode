class Solution {
public:
    typedef long long li;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        li sum =0;
        int count=0;
        int minloss=INT_MAX;

        for(li num : nums)
        {
            if((num ^ k) > num)
            {
                count++;
                sum+=(num ^k);
            }
            else
            {
                sum+=num;
            }
            minloss= min((long long)minloss,abs(num - (num ^k)));
        }
        if(count % 2 == 0)
        {
            return sum;
        }
        
            return sum - minloss;
        
    }
};