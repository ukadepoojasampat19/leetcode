class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int ch : nums){
            mp[ch]++;
        }
        for(auto num : mp){
           
            int first = num.first;
            int second = num.second;

            if(second == 1) return first;
        }

         return 0;    
    }
};