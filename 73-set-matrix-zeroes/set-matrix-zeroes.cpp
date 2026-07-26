class Solution {
public:

    void set_temp_zero(int i,int j, vector<vector<int>>& temp){
        int m = temp[0].size();
        int n = temp.size();
            int row = i;
            int col = j;
        while(i>=0){
             
            temp[i][j] = 0;
            i--;
        }
        i = row;
         while(i<n){
             
            temp[i][j] = 0;
            i++;
        }
        i = row;
         while(j>=0){
             
            temp[i][j] = 0;
            j--;
        }
        j = col;
         while(j<m){
             
            temp[i][j] = 0;
            j++;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
       
        int col = matrix[0].size();
        int row = matrix.size();
        vector<vector<int>> temp =  matrix;

        for(int i=0; i<row; i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    set_temp_zero(i,j, temp);
                }
            }
        }
        matrix = temp;

    }
};