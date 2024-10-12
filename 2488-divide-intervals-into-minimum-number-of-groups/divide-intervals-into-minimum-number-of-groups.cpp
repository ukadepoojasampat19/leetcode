class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> vec;


        for(auto & ch: intervals)
        {
            vec.push_back({ch[0] , 1});
            vec.push_back({ch[1] + 1, -1});
        }


        sort(vec.begin(),vec.end());

        int max_group =0;
        int curr_group = 0;

        for(auto&n: vec)
        {
            curr_group += n.second;
            max_group = max(max_group,curr_group);
        }
        return max_group;
    }
};