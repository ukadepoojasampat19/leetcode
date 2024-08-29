class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int row_ct = 0;
        int col_ct = 0;

        // Set to track visited stones
        vector<bool> visited(n, false);

        // Function to perform DFS and mark connected stones
        auto dfs = [&](int i, auto& dfs) -> void {
            visited[i] = true;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])) {
                    dfs(j, dfs);
                }
            }
        };

        // Count the number of connected components (i.e., stones that can't be removed)
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, dfs);
            }
        }

        // Number of stones that can be removed = Total stones - number of components
        return n - components;
    }
};
