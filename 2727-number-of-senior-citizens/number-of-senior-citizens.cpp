class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ct =0;
        for(int i=0;i<details.size();i++)
        {
            string temp = details[i];
            if((temp.substr(11,2)) > "60")
              {ct++;}
        }
        return ct;
    }
};