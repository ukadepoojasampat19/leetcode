class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for (int num : nums) {
            if (num <= first) {
                first = num; // update the smallest number
            } else if (num <= second) {
                second = num; // update the second smallest number
            } else {
                // found a number greater than both first and second
                return true;
            }
        }
        
        return false; // no such triplet found
    }
};
