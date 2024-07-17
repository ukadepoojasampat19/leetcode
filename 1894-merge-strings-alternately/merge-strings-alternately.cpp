class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result="";
        int w1 = word1.length();
        int w2 = word2.length();
        int i=0;
        while(i < w1 && i < w2)
        {
            result += word1[i];
            result += word2[i];
            i++;
        }
        while(i < w1)
        {
            result += word1[i];
            i++;
        }
        while(i< w2)
        {
            result += word2[i];
            i++;
        }
        return result;
        
    }
};