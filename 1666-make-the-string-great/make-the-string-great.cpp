class Solution {
public:
    string makeGood(string s) {
        /*if(s.length() == 1)
        {
            return s;
        }
        int st=0;
        
        while(st < s.length() -1 && s.length() != '\0')
        {
            char num1=s[st];
            char num2=s[st+1];

            if(num1 >= 'A' && num1 <='Z'|| num2 >= 'A' && num2 <='Z')
            {
                s=s.erase(st,2);
                st=0;
            }
            else
            {
                st++;
            }
              
            
           
        }
        return s;*/

        stack<char> stack;

        for(char c: s)
        {
            if(!stack.empty() && abs(c - stack.top()) == 32)
            {
                stack.pop();
            }else
            {
                stack.push(c);
            }
        }
        string result;
        while(!stack.empty())
        {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};