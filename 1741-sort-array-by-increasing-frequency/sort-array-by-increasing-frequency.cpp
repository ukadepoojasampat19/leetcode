class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> freq;
        vector<int> result;
        for(auto& n: nums)
        {
            mp[n]++;
        }
        for(auto& n: mp)
        {
            freq.push_back(n.second);
        }
        sort(freq.begin(),freq.end());
        int mp_size = mp.size();
        for(int i=0;i<freq.size();i++)
        {
            int fre_ele = freq[i];
            int max_ele = INT_MIN;
            for(auto& n: mp)
            {
                int a =  n.first;
                int b = n.second;
                if(b == fre_ele)
                {
                    max_ele = max(max_ele, a);
                }
            }
            mp[max_ele] = 0;
            while(fre_ele--)
            {
                result.push_back(max_ele);
            }
        }
        return result;
    }
};