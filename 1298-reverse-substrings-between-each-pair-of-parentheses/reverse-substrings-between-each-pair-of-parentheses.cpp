class Solution {
public:
    string reverseParentheses(string s) {
       stack<int> st;
       string result;

       for(auto &ch : s)
       {
          if(ch == '(')
          {
             st.push(result.length());
          }
          else if( ch == ')')
          {
            int start =  st.top();
                reverse(result.begin() + start, result.end());
                st.pop();
          }
          else
          {
                 result += ch;
          }
         
       }
       return result;
    }
};