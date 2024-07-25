class Solution {
public:
    string largestOddNumber(string num) {
       int num_size = num.length();
       for(int i= num_size-1;i>=0;i--){
         if((num[i] - '0') %2 != 0)
         {
                return num.substr(0, i+1);
         }
       }
       return "";
    }
};
