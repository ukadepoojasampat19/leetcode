class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     unordered_set<string> seen;

     for(int i=0;i<9;i++)
     {
        for(int j=0;j<9;j++)
        {
            char current=board[i][j];
            if(current != '.')
            {
                string row= "r_"+to_string(i)+"_"+current;
                string col= "c_"+to_string(j)+"_"+current;
                string box= "b_"+to_string(i/3)+"_"+to_string(j/3)+"_"+current;

                if(seen.count(row) || seen.count(col) || seen.count(box))
                {
                    return false;
                }

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }
     }

     return true;

        
    }
};