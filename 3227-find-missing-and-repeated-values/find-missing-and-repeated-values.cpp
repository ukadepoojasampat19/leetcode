class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mp;
        vector<int> res(2, 0); 
        int r = grid.size();
        int col = grid[0].size();

        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < col; j++) {
                mp[grid[i][j]]++;
            }
        }

        
        for (auto& n : mp) {
            if (n.second > 1) {
                res[0] = n.first; 
                break;
            }
        }

        
        for (int i = 1; i <= r * col; i++) {
            if (mp.find(i) == mp.end()) {
                res[1] = i; 
                break;
            }
        }

        return res;
    }
};