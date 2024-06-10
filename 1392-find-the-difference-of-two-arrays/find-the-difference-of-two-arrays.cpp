class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<vector<int>> result(2);

        // Find elements in nums1 that are not in nums2
        for (int num : nums1) {
            if (set2.find(num) == set2.end()) {
                result[0].push_back(num);
                set2.insert(num); // Avoid duplicates
            }
        }

        // Find elements in nums2 that are not in nums1
        for (int num : nums2) {
            if (set1.find(num) == set1.end()) {
                result[1].push_back(num);
                set1.insert(num); // Avoid duplicates
            }
        }

        return result;
    }
};
