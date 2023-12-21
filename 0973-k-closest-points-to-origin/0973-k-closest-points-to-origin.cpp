class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int row=points.size();
        int col= (row > 0) ? points[0].size() : 0;
        priority_queue<pair<int, pair<int,int>>> maxhp;
        vector<vector<int>> arr;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col-1;j++)
            {
                int sum=(points[i][j])*(points[i][j]) + (points[i][j+1])*(points[i][j+1]);
                    maxhp.push({sum,{points[i][j],points[i][j+1]}});
                
                    if(maxhp.size() > k)
                    {
                        maxhp.pop();
                    }
            }
            
                
        }
        ;
        while(maxhp.size() > 0)
        {
            pair<int,int> p=maxhp.top().second;
            arr.push_back({p.first,p.second});
            maxhp.pop();
        }
        return arr;
    }
};