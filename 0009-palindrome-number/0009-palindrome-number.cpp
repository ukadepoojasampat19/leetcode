class Solution {
public:
    bool isPalindrome(int x) {
        string numstr=to_string(x);
       int size=numstr.length();
        
        for(int i=0;i<size/2;i++)
        {
            if(numstr[i] != numstr[size-1-i])
            {
                return false;
            }
            
        }
        
        return true;
        
    }
};