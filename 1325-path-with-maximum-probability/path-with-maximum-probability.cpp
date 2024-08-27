class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        
        vector<double> maxproba(n,0.0);
        maxproba[start_node] =1.0;

        for(int i=0;i<n-1;i++)
        {
            bool updated = false;
            for(int j=0; j<edges.size(); j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];

                double prob = succProb[j];

                if(maxproba[u] * prob > maxproba[v])
                {
                    maxproba[v] = maxproba[u] * prob;
                    updated = true;

                }
                if(maxproba[v] * prob > maxproba[u])
                {
                    maxproba[u] = maxproba[v] * prob;
                    updated = true;
                }
            }
            if(!updated) break;
        }

        return maxproba[end_node];
    }
};