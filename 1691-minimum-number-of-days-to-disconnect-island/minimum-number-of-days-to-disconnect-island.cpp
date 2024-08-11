class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int row,int col,vector<vector<bool>>& vis)
    {
        if(i <0 || i>= row ||  j<0 || j>= col || grid[i][j] ==0 || vis[i][j])
        {
            return 0;
        }
        vis[i][j] = true;
        dfs(grid, i, j-1,row,col,vis);
        dfs(grid, i, j+1,row,col,vis);
        dfs(grid, i-1, j,row,col,vis);
        dfs(grid, i+1, j,row,col,vis);

        return 1;
    }
    int nofisland(vector<vector<int>>& grid,int row,int col)
    {
        int island =0;

        vector<vector<bool>> vis(row, vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if( grid[i][j] == 1 && !vis[i][j])
                {
                    island+= dfs(grid,i,j,row,col,vis);
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        //check for number of island if > 1 or ==0 thn return 0
        
        vector<vector<int>> temp = grid;
        int row = grid.size();
        int col = grid[0].size();

        int ct = nofisland(grid,row,col);
        if( ct > 1 || ct ==0)
        {
            return 0;
        }
        else
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(grid[i][j] == 1)
                    {
                        //int land =0;
                        grid[i][j] = 0;
                        ct = nofisland(grid,row,col);
                        if(ct > 1 || ct ==0)
                        {
                            return 1;
                        }
                         grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};