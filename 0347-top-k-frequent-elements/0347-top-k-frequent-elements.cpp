class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n= nums.size();
    vector<int> arr1;
        unordered_map <int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minhp;
    
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        minhp.push({i->second,i->first});
        if(minhp.size() > k)
        {
            minhp.pop();
        }
    }
    while(minhp.size() >0)
    {
        arr1.push_back(minhp.top().second);
        minhp.pop();
    }
        return arr1;
    }
};