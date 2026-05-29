class Solution {
public:
    int reverse(int x) {
        int newNum =0;
        while(x != 0){
            int lastDigit = x % 10;
              if (newNum > INT_MAX / 10 || (newNum == INT_MAX / 10 && lastDigit > 7))
                return 0;
            if (newNum < INT_MIN / 10 || (newNum == INT_MIN / 10 && lastDigit < -8))
            return 0;
            newNum = newNum * 10 + lastDigit;
            x = x/10;
        }
        return newNum;
    }
};