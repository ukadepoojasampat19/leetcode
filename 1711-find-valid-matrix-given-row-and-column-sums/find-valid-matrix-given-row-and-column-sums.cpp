class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();
        vector<vector<int>> res(row,vector<int>(col,0));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int val = min(rowSum[i],colSum[j]);
                res[i][j] = val;
                rowSum[i] = rowSum[i] - val;
                colSum[j] = colSum[j] -val;

            }
        }
        return res;
    }
};