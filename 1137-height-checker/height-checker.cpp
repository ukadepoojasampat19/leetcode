class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> expected;
        int ct=0;
        for(int i=0;i<heights.size();i++)
        {
            expected.push_back(heights[i]);
        }

        sort(expected.begin(), expected.end());

        for(int i=0;i< expected.size(); i++)
        {
            if(expected[i] != heights[i]) ct++;
        
        }

        return ct;


        
    }
};