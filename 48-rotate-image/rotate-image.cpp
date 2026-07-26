class Solution {
public:
  
    void rotate(vector<vector<int>>& matrix) {
     //   int n = matrix.size();
       
      //  vector<vector<int>> temp(n, vector<int>(n));
       // for(int i=0;i<n;i++){

           // vector<int> res(n);

           // for(int j=0;j<n;j++){

              //  temp[j][n-1-i] = matrix[i][j];
         //   }
            
       // }
       //optimal approach o(n2) time complexity 
        //space completit o(n*n); -> for storing the temp 2d vectore
        //matrix = temp;

        //optimal approach o(n2) time complexity 
        //space completit o(1);

        //calculate the transpose of the matrx(row become colum and column became row )
        //avoid diagonals
        int row =  matrix.size();
        int col = matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                if( i == j) continue;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        int i=0;
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};