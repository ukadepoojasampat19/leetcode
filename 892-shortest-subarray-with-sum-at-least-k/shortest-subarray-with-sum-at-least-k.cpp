#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0); // Prefix sum array
        
        // Compute prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq; // Monotonic deque to store indices
        int result = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Check if we can find a valid subarray
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                result = min(result, i - dq.front());
                dq.pop_front();
            }

            // Maintain monotonicity by removing useless indices
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            // Add current index to the deque
            dq.push_back(i);
        }

        return result == INT_MAX ? -1 : result;
    }
};
