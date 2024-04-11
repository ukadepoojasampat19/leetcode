class Solution {
public:
    string removeKdigits(string num, int k) {
        /*int n=num.size();
        vector<vector<string>> str;
        for(int i=0;i<(n-k+1);i++)
        {
            vector<string> temp;
            if(i>0)
            {
               temp.push_back(num.substr(0,i-1) +num.substr(n-i));
               str.push_back(temp);
            }
            temp.push_back(num.substr(i+k,n-i-1));
            str.push_back(temp);

        }
        sort(str.begin(),str.end());
        string temp=str[0][0];
        int pos=0;
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i]== '0')
            {
                pos++;
            }
        }
        temp=temp.substr(pos);
        return temp;
     */
      
      /* stack<char> stack;
        for(char c: num)
        {
            while(!stack.empty() && k > 0 && stack.top() > c)
            {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        //pop remaining largest num
        while(k > 0 && !stack.empty())
        {
            stack.pop();
            k--;
        }
        string res="";
        // Construct the result string from the stack
        while(!stack.empty())
        {
            res = stack.top() + res;
            stack.pop();
        }
        //remove leading zeros
        int pos = 0;
        while(pos < res.length() && res[pos] == '0')
        {
            pos++;
        }
        res = res.substr(pos);
        if(res.empty())
        {
            return "0";
        }
        return res;*/

        // 3rd 
     
            string res="";
        // stack<char> res;
        for(auto c: num)
        {
            while(!res.empty() && k>0 && res.back() > c)
            {
                res.pop_back();
                k--;
            }

            if(!res.empty()|| c!='0'){
                res+=c;
            }
            
            // res.push(c);
        }
            //remaing digits
            while(k>0 && !res.empty())
            {
                res.pop_back();
                k--;
            }
            if(res.empty()) return "0";
            // int pos=0;
            // while(pos < res.length() && res[pos] == '0')
            // {
            //     pos++;
            // }
            
        //     size_t pos = res.find_first_not_of('0');
        // res = (pos == std::string::npos) ? "0" : res.substr(pos);
        
        // return res;

        //     res=(pos == res.length()) ? "0" : res.substr(pos);
        //     return res;

        return res;
            
        }
        
    

    
};
