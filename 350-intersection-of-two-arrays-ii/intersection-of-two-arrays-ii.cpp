class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int,int> rp;
         vector<int> res;

         for(auto num: nums1)
         {
            rp[num]++;
         }
         for(auto num: nums2)
         {
            if(rp[num] > 0)
            {
                res.push_back(num);
                rp[num]--;
            }
         }

         return res;
    }
};