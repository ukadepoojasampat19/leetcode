class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int balance =0;
        for(auto& n: s)
        {
            if(n == '(')
            {
                if(balance >0)
                {
                    result +=n;
                }
                balance++;
            }
            else
            {
                balance--;
                if(balance > 0)
                {
                    result += n;
                }
            }
            
        }
        return result;
    }
};