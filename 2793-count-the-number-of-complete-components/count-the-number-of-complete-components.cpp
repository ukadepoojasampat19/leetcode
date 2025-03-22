class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n);

        unordered_map<string, int> freq_ct;

        for(int i=0;i<n;i++){
            graph[i].push_back(i);

        }

        for(const auto&edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            vector<int> neigbour = graph[i];
            sort(neigbour.begin(), neigbour.end());

            string key;
            for(int num : neigbour){
                key += to_string(num) + ',';
            }
            freq_ct[key]++;
        }
        int ans=0;
        for(const auto&entry : freq_ct){
            int size = count(entry.first.begin(), entry.first.end(), ',');
            if(size == entry.second){
                ans++;
            }
        }
                return ans;
    }
};