class Solution {
public:
    void markgrid(int row, int col, vector<vector<int>>& grid) {
        // up
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1;
        }
        // down
        for (int i = row + 1; i < grid.size(); i++) { // Fixed condition
            if (grid[i][col] == 2 || grid[i][col] == 3) {
                break;
            }
            grid[i][col] = 1;
        }
        // left
        for (int i = col - 1; i >= 0; i--) {
            if (grid[row][i] == 2 || grid[row][i] == 3) {
                break;
            }
            grid[row][i] = 1;
        }
        // right
        for (int i = col + 1; i < grid[0].size(); i++) { // Fixed condition
            if (grid[row][i] == 2 || grid[row][i] == 3) {
                break;
            }
            grid[row][i] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // mark guards
        for (vector<int> vec : guards) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2; // Guard cells
        }

        // mark walls
        for (vector<int> vec : walls) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3; // Wall cells
        }

        // mark guarded cells
        for (vector<int> vec : guards) { // Only mark grid from guard positions
            markgrid(vec[0], vec[1], grid);
        }

        // count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
