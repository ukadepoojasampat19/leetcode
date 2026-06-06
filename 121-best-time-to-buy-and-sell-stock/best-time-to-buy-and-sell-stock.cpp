class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min_prize= INT_MAX;
       int max_profit = 0;

       for(int price : prices){
           min_prize = min(min_prize, price);

           int profit = price - min_prize;

           max_profit = max(max_profit, profit);

       }
       return max_profit;

    }
};