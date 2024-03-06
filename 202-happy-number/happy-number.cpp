class Solution {
public:
    bool isHappy(int n) {
       unordered_set<int> map;

       while( n !=1 && map.find(n) == map.end())
       {
           map.insert(n);
           int sum=0;
           while(n > 0)
           {
               int digit=n % 10;
               sum+= digit * digit;
               n = n/10;

           }
           n =sum;
       }
       return n == 1;

    }
};