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
        int leftCount = 0;
        int rightCount = 0;
        std::stack<char> stack;

        // Pass 1
        for (char ch : s) {
            if (ch == '(') {
                leftCount++;
            } else if (ch == ')') {
                rightCount++;
            }
            if (rightCount > leftCount) {
                rightCount--;
                continue;
            } else {
                stack.push(ch);
            }
        }

        std::string result = "";
        
        // Pass 2
        while (!stack.empty()) {
            char currentChar = stack.top();
            stack.pop();
            if (leftCount > rightCount && currentChar == '(') {
                leftCount--;
            } else {
                result += currentChar;
            }
        }

        // Reverse the result string
        std::reverse(result.begin(), result.end());
        return result;
    }
};