class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<target.size();i++)
        {
            mp1[arr[i]]++;
            mp2[target[i]]++;

        }
        for(auto& n : mp1)
        {
            int first = n.first;
            int second = n.second;

            if(mp2.find(first) == mp2.end())
            {
                return false;
            }
            int fre = mp2[first];
            if(second != fre)
            {
                return false;
            }
        }
        return true;
    }
};