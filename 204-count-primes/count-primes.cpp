class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // Create a boolean array "isPrime[0..n-1]" and initialize
        // all entries it as true. A value in isPrime[i] will
        // finally be false if i is Not a prime, else true.
        vector<bool> isPrime(n, true);
        
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
        
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                count++;
            }
        }
        
        return count;
    }
};
