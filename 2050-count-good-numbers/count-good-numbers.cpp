class Solution {
private:
    static constexpr int mod = 1000000007;

    long long power(long long base, long long exponent) {
        long long result = 1;

        while (exponent > 0) {

            // If exponent is odd
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }

            // Square the base
            base = (base * base) % mod;

            // Divide exponent by 2
            exponent /= 2;
        }

        return result;
    }

public:
    int countGoodNumbers(long long n) {

        // Even indices: 0, 2, 4, ...
        // Each has 5 choices: 0, 2, 4, 6, 8
        long long evenPositions = (n + 1) / 2;

        // Odd indices: 1, 3, 5, ...
        // Each has 4 choices: 2, 3, 5, 7
        long long oddPositions = n / 2;

        long long evenWays = power(5, evenPositions);
        long long oddWays = power(4, oddPositions);

        return (evenWays * oddWays) % mod;
    }
};