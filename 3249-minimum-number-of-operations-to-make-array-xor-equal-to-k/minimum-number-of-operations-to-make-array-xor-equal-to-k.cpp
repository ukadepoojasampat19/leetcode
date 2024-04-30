class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int bit=0;bit<=20;bit++)
        {
            int Xor_val=0;
            for(auto& ele:nums)
            {
                int bit_val=(1<<bit) & ele;
                Xor_val=Xor_val ^ bit_val;
            }
            int k_val=(1<<bit) & k;
            if(Xor_val != k_val) ans++;
        }
        return ans;
    }
};