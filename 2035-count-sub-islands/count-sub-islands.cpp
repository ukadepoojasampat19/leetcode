class Solution {
public:
    // Perform DFS and check if grid2's island is valid sub-island with respect to grid1
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // If the current cell is out of bounds or water (0), return true (no issue).
        if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size() || grid2[i][j] == 0) {
            return true;
        }

        // If the corresponding cell in grid1 is water (0), mark this island as not sub-island.
        if (grid1[i][j] == 0) {
            return false;
        }

        // Mark the cell in grid2 as visited by setting it to 0
        grid2[i][j] = 0;

        // Check all four directions and combine the results.
        bool isSubIsland = true;
        isSubIsland &= dfs(i - 1, j, grid1, grid2);
        isSubIsland &= dfs(i + 1, j, grid1, grid2);
        isSubIsland &= dfs(i, j - 1, grid1, grid2);
        isSubIsland &= dfs(i, j + 1, grid1, grid2);

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid2.size();
        int col = grid2[0].size();
        int count = 0;

        // Traverse the grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Start DFS if a 1 is found in grid2
                if (grid2[i][j] == 1) {
                    // If DFS returns true, it means this is a valid sub-island
                    if (dfs(i, j, grid1, grid2)) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
