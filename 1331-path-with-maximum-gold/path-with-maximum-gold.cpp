class Solution {
public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int max_sum = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false)); 

    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] > 0) {
          max_sum = max(max_sum, dfs(grid, visited, i, j));
        }
      }
    }

    return max_sum;
  }

private:
  int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col]) {
      return 0;
    }

    visited[row][col] = true; 
    int current_gold = grid[row][col];

    int up = dfs(grid, visited, row - 1, col);
    int down = dfs(grid, visited, row + 1, col);
    int left = dfs(grid, visited, row, col - 1);
    int right = dfs(grid, visited, row, col + 1);

    visited[row][col] = false; 

    return current_gold + max({up, down, left, right});
  }
};
