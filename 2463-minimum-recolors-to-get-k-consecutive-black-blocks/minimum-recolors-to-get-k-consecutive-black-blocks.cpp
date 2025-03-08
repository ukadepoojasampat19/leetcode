class Solution {
public:
    int minimumRecolors(string blocks, int k) {
         int n = blocks.size();
    int whiteCount = 0;
    
    // Count white blocks in the first window of size k
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') {
            whiteCount++;
        }
    }
    
    int minOps = whiteCount;
    
    // Slide the window across the string
    for (int i = k; i < n; i++) {
        // Slide window: remove the left element and add the right element
        if (blocks[i - k] == 'W') {
            whiteCount--;
        }
        if (blocks[i] == 'W') {
            whiteCount++;
        }
        
        // Update the minimum operations needed
        minOps = std::min(minOps, whiteCount);
    }
    
    return minOps;
    }
};