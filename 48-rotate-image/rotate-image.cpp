class Solution {
public:
    void filled_temp(int r,int n,vector<vector<int>>& temp, vector<int>& res){
        for(int i=0;i<n;i++){
            temp[i][n-1-r] = res[i];
        }
    }

    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
       
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i=0;i<n;i++){

            vector<int> res(n);

            for(int j=0;j<n;j++){

                res[j] = matrix[i][j];
            }
            filled_temp(i,n,temp,res);
        }
        matrix = temp;
    }
};