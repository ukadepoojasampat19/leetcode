class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_value = arrays[0][0];
        int max_value = arrays[0].back();
        int result =0;
        for(int i=1;i<arrays.size();i++)
        {
            result = max(result, max(abs(max_value - arrays[i][0]),abs(min_value - arrays[i].back())));

            min_value = min(min_value, arrays[i][0]);
            max_value = max(max_value, arrays[i].back());
        }
        return result;
    }
};