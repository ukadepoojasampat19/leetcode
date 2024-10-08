class Solution {
public:
    int minSwaps(string s) {
        int imbalace = 0;
        int maximbalance = 0;


        for(auto& c : s)
        {
            if( c == '[')
            {
                imbalace--;
            }
            else
            {
                imbalace++;
            }

            maximbalance = max(maximbalance,imbalace);

        }
        return (maximbalance +1)/2;
    }
};