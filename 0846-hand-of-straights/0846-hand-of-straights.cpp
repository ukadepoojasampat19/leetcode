class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        int n=hand.size();
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }
        for(auto &it:mp)
        {
            int x=it.first;
            int y=it.second;
            if(y > 0)
            {
                for(int j=1;j<groupSize;j++)
                {
                    if(mp[x+j] >=y)
                    {
                        mp[x+j] -= y;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};