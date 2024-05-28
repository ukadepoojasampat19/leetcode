class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int maxlength=0;
       int sum=0;
       int st=0;

       for(int i=0;i<s.length();i++)
       {
          sum += abs(s[i] -t[i]);

          while(sum > maxCost)
          {
            sum -= abs(s[st]-t[st]);
            st++;
          }

          maxlength=max(maxlength,i-st+1);
       }
       return maxlength;
    }
};
