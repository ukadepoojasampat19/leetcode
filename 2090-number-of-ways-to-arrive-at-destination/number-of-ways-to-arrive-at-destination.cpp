#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        
        // Build adjacency list
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Min-Heap (Dijkstra)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        int mod = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            long long currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currDist > dist[node]) continue; // Skip outdated entries

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                long long adjDist = it.second;
                long long newDist = currDist + adjDist;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                    ways[adjNode] = ways[node]; // Reset path count
                } 
                else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // Add paths
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
