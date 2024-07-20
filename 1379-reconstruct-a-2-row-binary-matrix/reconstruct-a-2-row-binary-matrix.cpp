class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int col = colsum.size();
        vector<vector<int>> res(2, vector<int>(col, 0));

        // Process columns where colsum[i] == 2
        for (int i = 0; i < col; i++) {
            if (colsum[i] == 2) {
                if (upper > 0 && lower > 0) {
                    res[0][i] = 1;
                    res[1][i] = 1;
                    upper--;
                    lower--;
                } else {
                    return {}; // Not possible to satisfy the constraints
                }
            }
        }

        // Process columns where colsum[i] == 1
        for (int i = 0; i < col; i++) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    res[0][i] = 1;
                    upper--;
                } else if (lower > 0) {
                    res[1][i] = 1;
                    lower--;
                } else {
                    return {}; // Not possible to satisfy the constraints
                }
            }
        }

        // Check if we have used up all of upper and lower
        if (upper == 0 && lower == 0) {
            return res;
        } else {
            return {}; // Not possible to satisfy the constraints
        }
    }
};
