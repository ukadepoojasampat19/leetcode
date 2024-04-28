class Solution {
    int n_r,n_k;
    int dp[101][101];
public:
    int solve(string ring,string key,int i,int j)
    {
        //base condition
        if(i>=n_r || j>=n_k) return 0;

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        //key == ring then find next key 
        if(ring[i] == key[j])  return dp[i][j]= 1+ solve(ring,key,i,j+1);

        //ckeck clockwise and anticlockwise
        int lefti=i,righti=i;
        int dist1=0,dist2=0;

        //first left
        while(ring[lefti] != key[j])
        {
            lefti--;
            if(lefti <0) lefti=n_r-1;
            dist1++;
        }

        //right
        while(ring[righti] !=key[j])
        {
            righti++;
            if(righti == n_r) righti=0;
            dist2++;

        }
        //if both are at same locaton
        if(lefti==righti)
        {
            return dp[i][j]=min(dist1,dist2) +1 +solve(ring,key,lefti,j+1);
        }
        int ansL=dist1+1+solve(ring,key,lefti,j+1);
        int ansR=dist2+1+solve(ring,key,righti,j+1);

        return dp[i][j]= min(ansL,ansR);
    }
   int findRotateSteps(string ring, string key) {
      /*  unordered_map<char, vector<int>> positions;
        for (int i = 0; i < ring.size(); ++i) {
            positions[ring[i]].push_back(i);
        }
        vector<vector<int>> memo(key.size(), vector<int>(ring.size(), -1));
        return helper(0, 0, positions, key, ring, memo);*/
        /*----------------------------------------------------------------------------------------------------*/
        n_r=ring.size();
        n_k=key.size();
        memset(dp,-1,sizeof(dp));
        return solve(ring,key,0,0);


    }
};
    /*int helper(int in_index, int pos, unordered_map<char, vector<int>>& positions, string& key, string& ring, vector<vector<int>>& memo) {
        if (in_index == key.size()) {
            return 0;
     }
        if (memo[in_index][pos] != -1) {
            return memo[in_index][pos];
        }
        int min_steps = INT_MAX;
        for (int i : positions[key[in_index]]) {
            int steps;
            if (i >= pos) {
                steps = min(i - pos, static_cast<int>(pos + ring.size()) - i);
            } else {
                steps = min(pos - i, static_cast<int>(i + ring.size()) - pos);
            }
            int next_steps = helper(in_index + 1, i, positions, key, ring, memo);
            min_steps = min(min_steps, steps + next_steps);
        }
        memo[in_index][pos] = min_steps + 1;
        return min_steps + 1;
        */

