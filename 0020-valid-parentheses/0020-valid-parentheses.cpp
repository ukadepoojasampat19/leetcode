class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> num={{')', '('},{']','['},{'}','{'}};
        
        for(auto c: s)
        {
            if(num.find(c) !=num.end())
            {
                char current= stack.empty() ? '#' : stack.top();
                if(num[c] != current)
                {
                    return false;
                }
                stack.pop();
            }
             else
             {
                 stack.push(c);
        
              }
        }
       
        return stack.empty();
      
        
    }
    
  
};