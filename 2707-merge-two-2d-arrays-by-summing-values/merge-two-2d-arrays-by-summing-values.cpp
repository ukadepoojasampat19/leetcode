class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        vector<vector<int>> res;
        for(auto& num: nums1){
            int a = num[0];
            int b = num[1];
            mp[a] = b;
        }
        for(auto &num: nums2){
            int a=num[0];
            int b=num[1];
            if(mp.find(a) != mp.end()){
                int temp=mp[a];
                mp[a] = temp+b;
            }else
            {
                mp[a] = b;
            }
        }
       for(auto& n: mp){
        res.push_back({n.first,n.second});
       }
       return res;
    }
};