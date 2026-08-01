class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      

        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            //create a new row 
            res.push_back(vector<int>(i+1));
            for(int j=0; j<=i;j++){
                if(j == 0 || i==j){
                    res[i][j] = 1;
                    cout<<res[i][j]<<" ";
                    continue;
                }
                res[i][j] = res[i-1][j] + res[i-1][j-1];
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
        return res;
    }
};