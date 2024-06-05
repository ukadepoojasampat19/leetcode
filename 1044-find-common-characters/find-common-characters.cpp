class Solution {
public:
    void fillcount(string& word,int count[26])
    {
        for(char &n : word)
        {
            count[n - 'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
      vector<string> result;

      int count[26]={0};

      fillcount(words[0],count);

      for(int i=1;i<words.size();i++)
      {
         int temp[26]={0};
         fillcount(words[i],temp);

         for(int j=0;j<26;j++)
         {
            count[j]=min(count[j],temp[j]);
         }

      }

      for(int i=0;i<26;i++)
      {
         int c = count[i];
         while(c--)
         {
            result.push_back(string(1, i+'a'));
         }
        
      }
       return result;
    }
};