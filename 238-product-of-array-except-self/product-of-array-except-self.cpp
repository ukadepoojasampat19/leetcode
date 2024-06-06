class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);

        vector<int> left_pro(n);
        vector<int> right_pro(n);

        left_pro[0] = 1;
        for(int i=1; i<n; i++)
        {
            left_pro[i]=left_pro[i-1] * nums[i-1];
        }
        right_pro[n-1] = 1;
        for(int i=n-2; i>=0; i--)
        {
            right_pro[i] = right_pro[i+1] * nums[i+1];
        }

        for(int i=0; i<n; i++)
        {
            result[i] = left_pro[i] * right_pro[i];
        }
        return result;
    }
};