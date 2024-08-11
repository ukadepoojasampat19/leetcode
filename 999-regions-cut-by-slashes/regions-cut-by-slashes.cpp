class Solution {
public:
    int dfs(vector<vector<int>>& result, int i, int j, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col || result[i][j] == 1) {
            return 0;
        }
        result[i][j] = 1;
        dfs(result, i, j + 1, row, col);
        dfs(result, i - 1, j, row, col);
        dfs(result, i, j - 1, row, col);
        dfs(result, i + 1, j, row, col);

        return 1;
    }

    int regionsBySlashes(vector<string>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> result(row * 3, vector<int>(col * 3, 0));

        /* Explanation of grid transformation:
           ""  ->  0 0 0 
                    0 0 0
                    0 0 0
           "/" ->  0 0 1
                    0 1 0
                    1 0 0
           "\\"-> 1 0 0
                    0 1 0
                    0 0 1 */

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '/') {
                    result[i * 3][j * 3 + 2] = 1;
                    result[i * 3 + 1][j * 3 + 1] = 1;
                    result[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    result[i * 3][j * 3] = 1;
                    result[i * 3 + 1][j * 3 + 1] = 1;
                    result[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int region = 0;

        for (int i = 0; i < row * 3; i++) {
            for (int j = 0; j < col * 3; j++) {
                region += dfs(result, i, j, row * 3, col * 3);
            }
        }

        return region;
    }
};
