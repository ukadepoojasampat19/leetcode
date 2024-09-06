class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean * (m+n);
        int curr_sum=0;
        for(auto& n: rolls)
        {
            curr_sum += n;
        }
        int missing_sum = total_sum - curr_sum;
        //if the sum is in valid range 
        if(missing_sum < n || missing_sum > (n*6))
        {
            return {};
        }

        vector<int> result(n, missing_sum/n);
        int rem = missing_sum % n;
        for(int i=0;i<rem;i++)
        {
            result[i]++;
        }
        return result;
        
    }
};