class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word="";
        string words="";
        while(iss >> word)
        {
            words =word + " " +words;
        }
        return words.substr(0, words.length()-1);
        
    }
};