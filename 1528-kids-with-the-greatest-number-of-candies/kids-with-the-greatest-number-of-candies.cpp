class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> res;
     for(int i=0;i<candies.size();i++)
     {
        int a = candies[i]+extraCandies;
        int max_n=0;
        for(int j=0;j<candies.size();j++)
        {
            max_n=max(candies[j], max_n);
        }
        if(a >= max_n)
        {
            res.push_back(true);
        }
        else
        {
             res.push_back(false);
             }
     }
        return res;
    }
};