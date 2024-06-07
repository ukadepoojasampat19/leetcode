class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    unordered_map<string,int> mp;
    vector<string> temp;
    string result="";
    for(auto& n: dictionary)
    {
        mp[n]++;
    }
    istringstream iss(sentence);
    string word;
    while(iss >> word)
    {
        temp.push_back(word);
    }

    for(auto& dict_w : mp)
    {
        string temp_str = dict_w.first;
        
        for(int i=0;i<temp.size();i++)
        {
            int n=0,m=0;
            string sen_w = temp[i];
            while(n < temp_str.length()  && m < sen_w.length())
            {
                if(temp_str[n] != sen_w[m])
                {
                    break;
                }
                n++;
                m++;
            }
            if(n == temp_str.length())
            {
                temp[i] = temp_str;
            }
            
            
        }
    }

       for(int i=0;i<temp.size();i++)
       {
            result+=temp[i] + " ";
       } 
       return result.substr(0,result.length()-1);
    }
};