class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i;
        for(i=0;i<word.size();i++)
        {
                if(word[i] == ch)
                {
                    break;
                }
        }
        if(i == word.size())
        {
            return word;
        }
        int l=0;
        int r=i;
       while(l< r)
        {
            int a=word[l];
            word[l]=word[r];
            word[r]=a;
            l++;
            r--;

        }
        return word;
    }
};