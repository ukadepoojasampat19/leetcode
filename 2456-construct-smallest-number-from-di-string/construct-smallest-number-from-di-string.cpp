class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string res="";
        int n = pattern.size();
        int counter=1;
        for(int i=0;i<=n;i++){
                st.push(counter + '0');
                counter++;

                if( i ==n || pattern[i] == 'I'){
                    while(!st.empty()){
                        res += st.top();
                        st.pop();
                    }
                }
        }
        return res;
    }
};