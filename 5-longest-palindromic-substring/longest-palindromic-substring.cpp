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
         if (s.empty()) return "";
    
    int n = s.size();
    int start = 0, maxLen = 1;

    // Function to expand around center
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; ++i) {
        expandAroundCenter(i, i); // For odd length palindromes
        expandAroundCenter(i, i + 1); // For even length palindromes
    }

    return s.substr(start, maxLen);

    }
};