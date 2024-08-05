class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;

        for(auto& n: arr)
        {
            mp[n]++;
        }
        for(auto& n: arr)
        {
            if(mp[n] == 1) 
            {
                k--;
                if( k==0) return n;
            }
            
        }
        return "";
    }
};