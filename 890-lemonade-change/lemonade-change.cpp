class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five= 0;
        int ten =0;

        for(auto& n: bills)
        {
            if( n == 5) five++;
            if(n == 10) ten++;

            int change = n -5;
            if( change == 5)
            {
                if(five> 0) five--;
                else return false;
            }
            else if(change == 15)
            {
                if(five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if(five >= 3)
                {
                    five -=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};