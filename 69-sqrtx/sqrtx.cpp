class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Special case for 0 and 1
        
        int l = 1, r = x / 2;  // Range for binary search
        int ans = 0;  // This will store the closest integer square root
        
        while (l <= r) {
            int mid = l + (r - l) / 2;  // To avoid potential overflow
            long sqr = (long)mid * mid;  // Calculate mid^2
            
            if (sqr == x) {
                return mid;  // Exact square root found
            } else if (sqr < x) {
                ans = mid;  // Update the answer to mid
                l = mid + 1;  // Continue search in the right half
            } else {
                r = mid - 1;  // Continue search in the left half
            }
        }
        
        return ans;  // Return the closest integer square root
    }
};
