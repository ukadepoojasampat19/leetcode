class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> result;
        for(auto& n: queries)
        {
            int i = n[0];
            int j = n[1];
            int xor_sum=0;
            for(int k=i;k<=j;k++ && k < arr.size())
            {
               xor_sum = xor_sum ^ arr[k];
            }
            result.push_back(xor_sum);
        }
        return result;
    }
};