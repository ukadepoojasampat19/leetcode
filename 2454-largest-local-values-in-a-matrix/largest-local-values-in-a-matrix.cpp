class Solution {
public:
    int find_max(vector<vector<int>>& grid,int row, int col)
    {
        int max_val=0;
        for(int i=row;i<=row+2;i++)
        {
            for(int j=col;j<=col+2;j++)
            {
                max_val=max(max_val,grid[i][j]);
            }
        }
        return max_val;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2));
       for(int row=0;row<n-2;row++)
       {
           for(int col=0;col<n-2;col++)
           {
                maxLocal[row][col] = find_max(grid,row,col);
           }
       }
        
        return maxLocal;
        
    }
};