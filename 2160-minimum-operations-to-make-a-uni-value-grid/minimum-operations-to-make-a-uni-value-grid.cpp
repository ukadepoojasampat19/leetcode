class Solution {
public:
    
    int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> res;
            int length=0;

            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    res.push_back(grid[i][j]);
                }
            }

            sort(res.begin(), res.end());
            length = res.size();
            int count =0;
            int V = res[length/2];
            for(auto & num : res){
                if((num % x) !=( V % x))return -1;
                count += abs(V- num) / x;
            }

                return count;
        
    }
};