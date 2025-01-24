class Solution {
public:
    int dfs(int src , vector<vector<int>>& graph , vector<int>& v , vector<int>& s ){
        if(v[src] || s[src]) return s[src];

        v[src] = 1;
        for(int &dist: graph[src]){
            // if(v[dist]) continue;
            if(!dfs(dist,graph,v,s)){
                return 0;
            }
        }
        return s[src] =1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v(n,0), s(n,0) , ans;

        for(int i = 0 ; i < n ; i++){
            if(v[i]) continue;
            dfs(i, graph , v ,s);
        }
        for(int i = 0 ; i < n ; i++){
            if(s[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};