class Solution {
public:
    typedef pair<int, pair<int, int>> PP; // Define a type alias for convenience.

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();        // Number of rows.
        int n = heightMap[0].size();     // Number of columns.

        if (m <= 2 || n <= 2) return 0;  // If the height map is too small, no water can be trapped.

        // Min-heap to store boundary cells in ascending order of height.
        priority_queue<PP, vector<PP>, greater<>> boundaryCells;

        // Visited array to mark visited cells.
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Directions for neighbors: left, right, up, down.
        vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        // Add leftmost and rightmost columns to the boundaryCells.
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) { // Fix: Use `n-1` for the rightmost column.
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // Add topmost and bottommost rows to the boundaryCells.
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) { // Fix: Use `m-1` for the bottommost row.
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        // Process the boundary cells.
        while (!boundaryCells.empty()) {
            PP p = boundaryCells.top();
            boundaryCells.pop();

            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            // Visit all neighbors.
            for (pair<int, int>& dir : direction) { // Fix: Correct the type of `dir`.
                int i_ = i + dir.first;
                int j_ = j + dir.second;

                // Check bounds and ensure the neighbor is not visited.
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    // Calculate trapped water.
                    water += max(0, height - heightMap[i_][j_]);

                    // Push the neighbor cell into the heap with the maximum height.
                    boundaryCells.push({max(height, heightMap[i_][j_]), {i_, j_}});

                    // Mark as visited.
                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};
