class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        //BELOW APPROCH IS GREEDY
      /*   vector<int> check(dictionary.size(),0);

         for(int i=0;i<dictionary.size();i++)
         {
            string s1 = dictionary[i];
              for(int len=0;len <= s.length() - s1.length();len++)
              {
                    string temp = s.substr(len,s1.length());
                    if(s1 == temp)
                    {
                        check[i] =1;
                        
                    }
              }
         }
            cout<<"\n";
            for(int i=0;i<check.size();i++)
            {
                cout<<check[i]<<" ";
            }
            cout<<"\n";
            int str_count =0;
         for(int i=0;i<check.size();i++)
         {
                if(check[i] == 1)
                {
                    int n = dictionary[i].length();
                    str_count += n;

                }
         }
         cout<<"\n"<<"str_count: "<<str_count<<"\n";
         int m =s.length();
         return  m - str_count;*/
         //DP
         int n = s.length();
         vector<int> dp(n+1,n);
         dp[0] =0;

         unordered_set<string> dict(dictionary.begin(),dictionary.end());

         for(int i=0;i<s.length();i++)
         {
            dp[i+1] = min(dp[i+1],dp[i] +1);

            for(int len =1;len<=n-i;len++)
            {
                string substr = s.substr(i,len);
                if(dict.count(substr))
                {
                    dp[i+len] = min(dp[i+len],dp[i]);
                }
            }
         }
         return dp[n];
    }
};