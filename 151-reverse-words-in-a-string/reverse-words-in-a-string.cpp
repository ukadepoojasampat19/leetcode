class Solution {
public:
    string reverseWords(string s) {
        //buid in function
        string word;
        string words="";
        istringstream iss(s);
        while(iss >> word)
        {
            words=word+" "+words;
        }
        
        return words.substr(0,words.size()-1);

        //two pointer approach
        /*reverse(s.begin(),s.end());
        int l=0;
        int r=0;
        string result="";
        int i=0;
        int n=s.length();
        while(i < n)
        {
            while(i < n && s[i] !=' ')
            {
                s[r++]=s[i++];

            }
            if(l <r)
            {
                 reverse(s.begin()+l, s.begin()+r);
                 s[r]=' ';
                    r++;
                    l=r;
            }
           
            i++;
        }
        return s.substr(0,r-1);*/

    }
};