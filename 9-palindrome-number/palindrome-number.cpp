class Solution {
public:
    bool isPalindrome(int x) {
       long long result =0;
      int real_no = x;
       if(x < 0) return false;

       while( x > 0){
        int last_digit =  x % 10;
        result = (result * 10) + last_digit;
        x = x / 10;
       }
       
       return result ==  real_no;
    }
};