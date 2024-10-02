class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        vector<int> res(arr.size());

        int ct =1;
        unordered_map<int,int> mp;
        
        for(int i=0;i<temp.size();i++)
        {
            if(!mp.count(temp[i]))
            {
                mp[temp[i]] = ct;
                ct++;
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            if(mp.count(arr[i]))
            {
                res[i] = mp[arr[i]];
            }
        }
        return res;
    }
};