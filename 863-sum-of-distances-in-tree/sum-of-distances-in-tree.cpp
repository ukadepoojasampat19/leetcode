#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<int> count;
    vector<int> result;
    vector<vector<int>> *adj;
    int N;

    void dfs1(int node, int parent) {
        for (int child : (*adj)[node]) {
            if (child == parent) continue;
            dfs1(child, node);
            count[node] += count[child];
            result[node] += result[child] + count[child];
        }
    }

    void dfs2(int node, int parent) {
        for (int child : (*adj)[node]) {
            if (child == parent) continue;
            result[child] = result[node] - count[child] + (N - count[child]);
            dfs2(child, node);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        adj = new vector<vector<int>>(n);

        for (const auto& edge : edges) {
            int m = edge[0];
            int n = edge[1];
            (*adj)[m].push_back(n);
            (*adj)[n].push_back(m);
        }

        count.assign(n, 1);
        result.assign(n, 0);

        dfs1(0, -1);
        dfs2(0, -1);

        delete adj;

        return result;
    }
};
