class Solution {
public:
    int countDigits(int num) {
        int ct =0;
        int n= num;
        while(n > 0){

            int digit = n % 10;

            if(digit !=0 && num % digit == 0){
                ct++;
            }
            n = n/10;
        }
return ct;
    }
};