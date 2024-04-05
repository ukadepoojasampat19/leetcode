class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> temp;
        temp.push(-1);
        int maxlen=0;
        for(int i=0;i< s.length();i++)
        {
            if( s[i] == '(')
            {
                temp.push(i);
            }
            else
            {
                temp.pop();
                if(!temp.empty())
                {
                    maxlen=max(maxlen,i-temp.top());
                }
                else
                {
                    temp.push(i);
                }
            }
         }
         return maxlen;
        
    }
};