class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ct1=0;
        int ct2=0;
        for(int i=0;i<32;i++){
            if((1 << i) & num1)
            {
                ct1++;
            }
            if((1 << i) & num2)
            {
                ct2++;
            }
        }
            int res=num1;

        for(int i=0;i<32;i++){
            if((ct1 > ct2 )  && ((1 << i) & num1))
            {
                    res ^= (1 << i);
                    ct1--;
            }
            if( (ct1 < ct2) && !((1 << i) & num1)){
                 res ^= (1 << i);
                    ct1++;
            }
        }
        return res;
    }
};