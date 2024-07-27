class Solution {
public:
    typedef  pair<int,char>P;
    void  dijikstra(int n ,char S,unordered_map<char,vector<pair<char,int>>> adj,vector<vector<int>> &result)
    {
        priority_queue<P,vector<P>, greater<P>> pq;
      // fill(result.begin(),result.end(),INT_MAX);
        result[S-'a'][S -'a'] = 0;
        pq.push({0,S});

        while(!pq.empty())
        {
            int d = pq.top().first;
            char node = pq.top().second;
            pq.pop();

            //neigoubour node visit krayche
            for(auto& vec: adj[node])
            {
                char neigbour = vec.first;
                int wgt = vec.second;
                if(d+wgt < result[S-'a'][neigbour -'a'])
                {
                    result[S-'a'][neigbour -'a'] = d+wgt;
                    pq.push({d+wgt, neigbour});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<int>> SPM(26,vector<int>(26,INT_MAX));
        long long count =0;
        unordered_map<char,vector<pair<char,int>>> adj;
        for(int i=0;i<n;i++)
        {
            char u = original[i];
            char v = changed[i];
            int d = cost[i];
            adj[u].push_back({v,d});
        }

        for(char i = 'a';i<='z';i++)
        {
            // char curr_char = source[i];
            dijikstra(source.size(),i, adj,SPM);
        }
        for(int i=0;i<source.size();i++)
        {
            if(source[i] != target[i])
            {
                int a = source[i] - 'a';
                int b = target[i] - 'a';
                if(SPM[a][b]==INT_MAX) return -1;
                count += SPM[a][b];
            }
        }
        return count;
    }
};