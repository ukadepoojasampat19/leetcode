class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        
        long long temp;
        if(n == 1) return 1;
        for(int i=2;i<=n;i++){
            temp=(4*(i-1));
            ans+=temp;
        }
        return ans;
    }
};