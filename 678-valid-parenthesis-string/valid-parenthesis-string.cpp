class Solution {
public:
    bool checkValidString(string s) {
      /*  int l_ct=0;
        int r_ct=0;
        int start_ct=0;
       
        for(int i=0;i<s.length();i++)
        {
            char num=s[i];
            if(num == '(')
            {
                l_ct++;
            }
            else if(num == ')')
            {
                r_ct++;
            }
            else if(num == '*')
            {
                start_ct++;
            }
            
        }
        if(l_ct == r_ct)
        {
            return true;
        }
        while(l_ct != r_ct)
        {
            if(l_ct == r_ct)
            {
                return true;
            }
            else if(r_ct > l_ct)
            {
                if(start_ct != 0)
                {
                    l_ct++;
                    start_ct--;
                }
            }
            else if(l_ct > r_ct)
            {
                if(start_ct != 0)
                {
                    r_ct++;
                    start_ct--;
                }
            }
        }
        return false;*/
        int leftMin = 0, leftMax = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0;
        }
        
        return leftMin == 0;

        }
};