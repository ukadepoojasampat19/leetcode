class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> set1(nums1.begin(),nums1.end());
        set<int> set2(nums2.begin(),nums2.end());
        vector<int> res;
       // set1= sortedset1(set1.begin(),set1.end());
        //set2= sortedset2(set2.begin(),set2.end());

        set_intersection(
            set1.begin(),set1.end(),
            set2.begin(),set2.end(),
            back_inserter(res)
        );

        return res;
        
    }
};