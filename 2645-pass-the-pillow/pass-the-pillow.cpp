class Solution {
public:
    int passThePillow(int n, int time) {
       int num = 1;
       int direction =1;
       while( time > 0)
       {
         if(num ==1)
         {
            direction =1;
         }
         else if(num == n)
         {
            direction =-1;
         }
         num += direction;
         time--;
       }
       return num;
    }
};