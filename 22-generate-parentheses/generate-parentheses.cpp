class Solution {
public:
    void backtrack(vector<string>& result,string current,int l,int r,int n)
    {
        if(current.size() == 2*n)
        {
            result.push_back(current);
            return;
        }
        if(l < n)
        {
            current.push_back('(');
            backtrack(result,current,l+1,r,n);
            current.pop_back();
      
        }
        if( r< l)
        {
            current.push_back(')');
             backtrack(result,current,l,r+1,n);
             current.pop_back();

        }
    }
    vector<string> generateParenthesis(int n) {
         vector<string> result;
         string current;

         backtrack(result,current,0,0,n);
         return result;
    }
};