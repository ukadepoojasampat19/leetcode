class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int o_size =original.size();
        if(m*n != o_size) return {};
        vector<vector<int>> res(m,vector<int>(n,0));
    
        int st=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(st < o_size)
                {
                    res[i][j] = original[st];
                    st++;
                }
               
            }
        }
        return res;
    }
};