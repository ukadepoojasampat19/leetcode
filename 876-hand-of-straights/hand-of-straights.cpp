class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto& n: hand)
        {
            mp[n]++;
        }

        for(auto& n: mp)
        {
            int x = n.first;
            int y = n.second;
            if (y > 0) {
                for(int j = 1; j < groupSize; j++)
                {
                    if(mp[x + j] >= y)
                    {
                        mp[x + j] -= y;
                    }
                    else
                    {
                        return false;
                    }
                }
                mp[x] = 0; // Ensure the current card count is set to 0 after processing
            }
        }
        return true;
    }
};
