class Solution {
public:
    int minChanges(int n, int k) {
        int res =0;

        for(int i=0;i<32;i++)
        {
            int a = (n >> i & 1);
            int b = (k >> i & 1);
            if( a== 0 && b ==1) return -1;
            if(a ==1 && b==0) res++;
        }
        return res;
    }
};