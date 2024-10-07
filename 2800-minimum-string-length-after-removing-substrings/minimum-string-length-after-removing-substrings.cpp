class Solution {
public:
    int minLength(string s) {
        stack<char> st;


        for(int i=0;i<s.length();i++)
        {
            char curr_char = s[i];
            if(st.empty())
            {
                st.push(curr_char);
            }
            else if(curr_char == 'B' && st.top() == 'A')
            {
                st.pop();
            }
            else if(curr_char == 'D' && st.top() == 'C')
            {
                st.pop();
            }
            else
            {
                st.push(curr_char);
            }

        }
        return st.size();
    }
};