class Solution {
public:
    void  dfs(vector<bool>& visited,vector<vector<int>>& stones,int idx)
    {
        visited[idx] = true;

        for(int i=0;i<stones.size();i++)
        {
            int r = stones[idx][0];
            int col = stones[idx][1];
            if(visited[i] == false && (stones[i][0] == r || stones[i][1] == col))
            {
                dfs(visited, stones, i);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool> visited(n,false);
        int group=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i] == true) continue;

            dfs(visited,stones,i);
            group++;
        }
        return n- group;
    }
};