class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      int total_drunk = 0;
      int total_empty = 0;

      while(numBottles > 0)
      {
         total_drunk += numBottles;
         total_empty += numBottles;

         numBottles = total_empty / numExchange;
         total_empty = total_empty % numExchange;

      }
        return total_drunk;
    }
};