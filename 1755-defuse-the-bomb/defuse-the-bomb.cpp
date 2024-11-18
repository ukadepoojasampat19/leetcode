class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
         int n = code.size();
    vector<int> result(n, 0);

    // Special case: if k == 0, all numbers are replaced with 0
    if (k == 0) {
        return result;
    }

    // If k > 0, calculate the sum of the next k numbers
    if (k > 0) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 1; j <= k; j++) {
                sum += code[(i + j) % n]; // Wrap around using modulo
            }
            result[i] = sum;
        }
    } 
    // If k < 0, calculate the sum of the previous k numbers
    else {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 1; j <= -k; j++) {
                sum += code[(i - j + n) % n]; // Wrap around using modulo
            }
            result[i] = sum;
        }
    }

    return result;
        
    }
};