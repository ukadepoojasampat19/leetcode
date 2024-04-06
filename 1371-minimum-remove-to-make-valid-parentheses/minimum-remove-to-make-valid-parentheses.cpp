class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*stack<char> temp;
        int ct=0;
        for(int i=0;i<s.length();i++)
        {
            char num= s[i];
            temp.push(num);
            if(num == '(')
            {
                ct++;
            }
            else if(num == ')')
            {
                ct--;
                if(ct < 0)
                {
                    temp.pop();
                    ct=0;
                }
            }
           
        }
        string result="";
       if(ct == 0)
        {
            while(!temp.empty())
           {
             result = temp.top() + result;
             temp.pop();
           }
           return result;
        }
        return result;*/
       int l_ct=0;
       int r_ct=0;
        stack<char> temp;
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
            if(r_ct > l_ct)
            {
                r_ct--;
                continue;
            }
            else
            {
                temp.push(num);
            }
        }
        string result="";
        while(!temp.empty())
        {
            char num=temp.top();
            temp.pop();
            if(l_ct > r_ct && num =='(')
            {
                l_ct--;
            }
            else
            {
                result+=num;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};