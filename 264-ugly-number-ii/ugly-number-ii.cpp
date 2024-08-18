class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0; // Indices for 2, 3, 5
        
        for(int i = 1; i < n; ++i) {
            int nextUgly = min({uglyNumbers[i2] * 2, uglyNumbers[i3] * 3, uglyNumbers[i5] * 5});
            uglyNumbers[i] = nextUgly;
            
            // Increment the pointer(s) that match the next ugly number
            if(nextUgly == uglyNumbers[i2] * 2) ++i2;
            if(nextUgly == uglyNumbers[i3] * 3) ++i3;
            if(nextUgly == uglyNumbers[i5] * 5) ++i5;
        }
        
        return uglyNumbers[n-1];
    }
};
