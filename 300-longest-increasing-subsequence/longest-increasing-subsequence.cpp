class Solution {
public:
    int n;
    int memo[2501][2501];
    int  solve(vector<int>& nums,int i,int p)
    {

        if(i == n) return 0;

        if(p != -1 && memo[p][i] != -1) return memo[p][i];


        //take
        int take =0;
        if( p == -1|| nums[i] > nums[p])
        {
             take = 1+ solve(nums,i+1,i);

        }

        //skip
        int skip = solve(nums,i+1,p);
        if(p != -1)
        {
            memo[p][i] = max(take,skip);
        }
        return max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
         n = nums.size();
           memset(memo,-1,sizeof(memo));
        return solve(nums,0,-1);
        
    }
};