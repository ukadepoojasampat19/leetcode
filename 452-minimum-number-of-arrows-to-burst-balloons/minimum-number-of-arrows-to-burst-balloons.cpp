class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
        {
            return 0;
        }
        //sort points by its end points
        sort(points.begin(),points.end(), [](const vector<int>&a , const vector<int>& b)
        {
            return a[1]< b[1];
        });

        int ct=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0] > end)
            {
                ct++;
                end=points[i][1];
            }
        }
        return ct;
    }
};