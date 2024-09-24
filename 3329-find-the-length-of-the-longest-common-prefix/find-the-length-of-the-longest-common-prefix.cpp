class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string> st;

        for(int i=0;i<arr2.size();i++)
        {
            string s2 = to_string(arr2[i]);

            for(int len =1;len<=s2.length();len++)
            {
                st.insert(s2.substr(0,len));
            }
        }
        
        //inetrate arr1
        int max_len =0;
        for(int i=0;i<arr1.size();i++)
        {
            string s1 = to_string(arr1[i]);

            for(int len =0;len<=s1.length();len++)
            {
                if(st.count(s1.substr(0,len)))
                {
                    max_len = max(max_len, len);
                }
            }
        }
        return max_len;
    }
};