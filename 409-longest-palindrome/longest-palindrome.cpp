class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        
        for (char ch : s)
            counts[ch]++;
        
        int sum=0;
        bool check =false;
        for(auto& n: counts)
        {
            sum+= n.second / 2 * 2;
            if( n.second % 2 == 1)
            {
                check=true;
            }
            
        }
        if(check)
        {
            sum++;
        }
        return sum;
    }
};