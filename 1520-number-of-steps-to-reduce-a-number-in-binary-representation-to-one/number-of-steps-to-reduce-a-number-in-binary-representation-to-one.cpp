class Solution {
public:
    int numSteps(string s) {

    /*int steps=0;
    
    while(s.length() > 1)
    {
        int n=s.length();
        if(s[n-1] == '1')
        {
            int st=s.length() -1;
            while(st >=0 && s[st] == '1')
            {
                s[st]='0';
                st--;
            }
            if(st >=0)
            {
                 s[st]='1';
            }
            else
            {
                s = '1' +s;
            }
           
           
        }
        else
        {
            s.pop_back();
          

        }
          steps++;
    }   
    return steps;*/

    int op=0;
    int  n=s.length()-1;
    int carry=0;
    for(int i=n;i>=1;i--)
    {
        
        int num= (s[i] -'0') + carry;
       
         if(num % 2 != 0)
         {
              op+=2;
            carry=1;
           
         }
       else
        {
            op+=1;
        }
    }    
    return op + carry;
    }
    
};