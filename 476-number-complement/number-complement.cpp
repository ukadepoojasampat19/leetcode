class Solution {
public:
    int findComplement(int num) {
        int ct_bits =0;
        int n = num;
        while(num != 0)
        {
            num = num >> 1;
            ct_bits++;
        }
        int a = pow(2,ct_bits) -1;

        int ans =(a ^ n);
        return ans;
        
    }
};