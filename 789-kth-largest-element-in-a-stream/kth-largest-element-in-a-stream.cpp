#include <iostream>
#include <queue>
#include <vector>

class KthLargest {
public:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int n : nums) {
            add(n);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop(); // Maintain the heap size to be at most k
        }
        return pq.top(); // The top element is the kth largest
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
