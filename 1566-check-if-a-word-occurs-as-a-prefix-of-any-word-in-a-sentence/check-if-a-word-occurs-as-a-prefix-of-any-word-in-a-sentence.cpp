class Solution {
public:
    vector<string> split(string s){
        vector<string> ans;
        int i = 0 , j = 0;
        int n = s.length();
        while(j<n){
            while(j<n && s[j]!=' ') j++;
            string str = s.substr(i, j-i);
            if(str!="") ans.push_back(str);
            j++;
            i = j;
        }
        return ans;
    }
    int isPrefixOfWord(string sentence, string target) {
        vector<string> s = split(sentence);
        int n = target.length();
        for(int j = 0 ; j < s.size() ; j++){
            string i = s[j];
            int l = i.length();
            if(l>=n && i.substr(0,n)==target) return j+1;
        }
        return -1;
    }
};