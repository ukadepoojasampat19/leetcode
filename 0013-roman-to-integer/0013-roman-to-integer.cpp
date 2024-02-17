class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_value={
            {'I' , 1},
            {'V', 5},
            {'X', 10},
            {'L' , 50},
            {'C', 100},
            {'D',500},
            {'M', 1000}
        };
        
        int result=0;
        
        for(int i=0;i< s.length();i++)
        {
            if(i>0 && roman_value[s[i]] >roman_value[s[i-1]] )
            {
                //subtraction case;
                result+=roman_value[s[i]] - 2* roman_value[s[i-1]];
            }
            else
            {
                result+=roman_value[s[i]];
            }
        }
        
        return result;
    }
};