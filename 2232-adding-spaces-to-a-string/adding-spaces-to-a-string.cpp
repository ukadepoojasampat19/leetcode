class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int prev=0;
        for(const int n: spaces)
        {
            result += s.substr(prev, n- prev);
            result += " ";
            prev = n;
        }
        result += s.substr(prev);
        return result;
    }
};