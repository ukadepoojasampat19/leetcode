class Solution {
public:
    const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int g = n * (n+1) /2;
        int temp[g];
        int k=0;
        int sum=0;
        for(int i = 0;i<n;i++)
        {
            temp[k] = nums[i];
            k++;
            for(int j=i+1;j<n;j++)
            {
                temp[k] = temp[k-1] + nums[j];
                k++;
            }
        }
        sort(temp,temp + g);
        for(int i=0;i<g;i++)
        {
            cout<<temp[i]<<" ";
        }
        for(int i=left-1;i<right;i++)
        {
            sum = (sum + temp[i]) % MOD;
        }
        return sum;
    }
    
};