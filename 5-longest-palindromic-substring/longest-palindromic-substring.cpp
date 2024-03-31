class Solution {
public:
    string longestPalindrome(string s) {
       /* int l=0,r=0,mx=INT_MIN;
        string temp;
        vector<vector<string,string>> final;
        while(r < s.length())
        {
            temp+=s.substr(1);
            if(s[l] == s[r+1] && r < s.length())
            {
                temp+=s.substr(1);
                int n=temp.length();
                int mid=n /2;
                int st=mid-1;
                int ed=mid+1;
                bool state=false;
            
                while(st < 0 && ed > n)
                {
                    if(temp[st] == temp[ed])
                    {
                        state=true;
                    }
                    else
                    {
                        state=false;
                    }
                    
                }
                if(state)
                {
                    final.push_back(temp);

                }
            }
            r++;
        }
        int index=0;
        for(int i=0;i<final.size();i++)
        {
            mx=max(mx,final[i].size());
            if(mx==final[i].size())
            {
                index=i;
            }
            else
            {
                index=i-1;
            }
        }
        return final[index];*/
         int n = s.size();
    if (n == 0) return "";
    
    // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Initialize variables to track the longest palindrome found.
    int start = 0, maxLen = 1;

    // Every single character is a palindrome.
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // Palindromes of length 2.
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Palindromes of length greater than 2.
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; // End index of current substring.

            // If current substring is palindrome and outer characters are same.
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }

    return s.substr(start, maxLen);
    }
};