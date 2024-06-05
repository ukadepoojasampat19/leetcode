class Solution {
public:
    string reverseVowels(string s) {
        int l=0;
        int r=s.length() -1;
        string word=s;
       string vowels="aeiouAEIOU";
       
        while(l < r)
        {
            while(l<r && vowels.find(word[l]) == string::npos)
            {
                l++;
            }
            while(l<r && vowels.find(word[r]) == string::npos)
            {
                r--;
            }
            if(l<r)
            {
                swap(word[l],word[r]);
            l++;
            r--;
            }
            
        }
        return word;
    }
};