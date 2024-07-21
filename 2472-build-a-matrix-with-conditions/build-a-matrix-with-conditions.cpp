class Solution {
public:
    void dfs(int u, vector<int>& visited, unordered_map<int, vector<int>>& adj, stack<int>& st, bool& cycle) {
        visited[u] = 1;
        for (int &v : adj[u]) {
            if (visited[v] == 0) {
                dfs(v, visited, adj, st, cycle);
            } else if (visited[v] == 1) {
                cycle = true;
                return;
            }
        }
        visited[u] = 2;
        st.push(u);
    }

    vector<int> toposort(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> visited(n + 1, 0);
        vector<int> order;
        stack<int> st;
        bool cycle = false;

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, visited, adj, st, cycle);
                if (cycle == true) {
                    return {};
                }
            }
        }

        while (!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row_value = toposort(rowConditions, k);
        vector<int> col_value = toposort(colConditions, k);

        if (row_value.empty() || col_value.empty()) {
            return {};
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        unordered_map<int, int> pos;
        for (int i = 0; i < k; i++) {
            pos[col_value[i]] = i;
        }

        for (int i = 0; i < k; i++) {
            res[i][pos[row_value[i]]] = row_value[i];
        }

        return res;
    }
};
