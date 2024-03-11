class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> chtow;
        unordered_map<string,char> wtoch;

        istringstream iss(s);
        vector<string> word;

        //split the string into words
        while(iss >> s)
        {
            word.push_back(s);
        }

        if(pattern.length() != word.size())
        {
            return false;
        }

        for(int i=0;i<pattern.length();i++)
        {
            char num1=pattern[i];
            string num2=word[i];
            if(chtow.count(num1) && chtow[num1] != num2)
            {
                return false;
            }

            if(wtoch.count(num2) && wtoch[num2] != num1)
            {
                return false;
            }
            chtow[num1]= num2;
            wtoch[num2]=num1;
        }

        return true;
        
    }
};