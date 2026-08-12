class Solution {
public:
    double myPow(double x, int n) {
       long long exponent = n;
       double base = x;
       double result =1;

//- ve exponent

if(exponent < 0){
    base= 1/base;
    exponent = -exponent;
}
//+ ve exponents 
       while(exponent > 0){

        if(exponent % 2 == 1){
            result = result * base;
        }

        base = base * base;

        exponent=exponent/2;
       }

       return result;




    }
};