class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int first = edges[0][0];
        int second = edges[0][1];
        int i;
        for(i=1;i<edges.size();i++)
        {
            if(first != edges[i][0] && first != edges[i][1])
            {
                break;
            }
            
        }
        if(i == edges.size()) return first;
        return second;
    }
};