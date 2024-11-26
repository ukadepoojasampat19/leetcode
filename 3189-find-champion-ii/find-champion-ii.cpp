class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);

        for(vector<int> edge: edges)
        {
            int u= edge[0];
            int v= edge[1];
            indegree[v]++;

        }
        int champaion = -1;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                if(champaion == -1)
                {
                    champaion=i;
                }
                else
                {
                    return -1;
                }
            }
        }
        return champaion;
    }
};