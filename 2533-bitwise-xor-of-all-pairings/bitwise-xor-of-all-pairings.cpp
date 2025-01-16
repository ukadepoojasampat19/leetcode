class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();

        unordered_map<int, long> freq;

        for(auto & num: nums1){
            freq[num] += l2;
        }
         for(auto & num: nums2){
            freq[num] += l1;
        }
        int ans =0;
        for(auto & res : freq){
            int n = res.second;
            if(n % 2 == 1)
            {
                    ans ^= res.first;
            }
        }
        return ans;
    }
};