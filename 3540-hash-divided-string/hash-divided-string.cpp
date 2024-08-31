class Solution {
public:
   
    string stringHash(string s, int k) {
        int n = s.length();
        int mid = n/k;
        string result;
        vector<string> res;
        if(n % k!= 0)
        {
            return "";
        }
        for(int i=0;i<s.length();i+=k)
        {
            string temp = s.substr(i,k);
            int num =0;
            for(char val : temp)
            {
               num += val- 'a';
            }
            int sum = num % 26;
             result+= sum +'a';
            
        }
        return result;
    }
};