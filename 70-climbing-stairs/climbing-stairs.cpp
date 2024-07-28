class Solution {
public:
    int st(int n,vector<int>& memo)
    {
        if( n==0 || n==1)
        {
            return 1;
        }
        if(memo[n] != -1) return memo[n];
        memo[n] = st(n-1,memo) + st(n-2,memo);
        return memo[n];
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return st(n,memo);

        
    }
};