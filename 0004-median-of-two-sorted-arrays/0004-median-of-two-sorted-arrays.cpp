class Solution {
public:
    
    void merge_sort(vector<int>& nums1, vector<int>& nums2, int idx, vector<int>& result) {
        
        int l = idx;
        int r = idx;
        
        while (l < nums1.size() && r < nums2.size()) {
            if (nums1[l] < nums2[r]) {
                result.push_back(nums1[l]);
                l++;
            } else {
                result.push_back(nums2[r]);
                r++;
            }
        }
        
        while (l < nums1.size()) {
            result.push_back(nums1[l]);
            l++;
        }
        
        while (r < nums2.size()) {
            result.push_back(nums2[r]);
            r++;
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        double final_n;
        
        merge_sort(nums1, nums2, 0, result);
        
        int total_size = result.size();
        
        if (total_size % 2 != 0) {
            int res = total_size / 2;
            final_n = result[res];
        } else {
            int res = total_size / 2;
            final_n = (result[res - 1] + result[res]) / 2.0;  // Make sure to use 2.0 for correct floating-point division
        }
        
        return final_n;
    }
};
