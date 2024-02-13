#include <unordered_set>

class Solution {
public:
     void subset(string ip,string op,vector<string>& result, unordered_set <string>& uniqueStrings)
     {
         if(ip.empty())
         {
             if(uniqueStrings.find(op) == uniqueStrings.end())
             {
                  result.push_back(op);
                  uniqueStrings.insert(op);
             }
              return;
         }
         string op1=op + ip[0];
         string op2;
         if(islower(ip[0]))
         {
              op2=op + char(toupper(ip[0]));
         }
         else
         {
            op2=op + char(tolower(ip[0]));
         }
        
          
          ip = ip.substr(1);
         
          subset(ip,op1,result,uniqueStrings);
          subset(ip,op2,result,uniqueStrings);
         
        /* string op1=op + ip[0];
         ip=ip.substr(1);
         subset(ip,op1,result);
         
         if(isalpha(ip[0]))
         {
            string op2 = op + char(toupper(ip[0]));
             if(!ip.substr(1).empty())
             {
                  subset(ip.substr(1),op2,result);
                 
             }
           
         }
       subset(ip.substr(1),op,result);*/
         
     }
    vector<string> letterCasePermutation(string s) {
        string op="";
        string ip=s;
        vector<string> result;
        unordered_set <string> uniqueStrings;
        subset(ip,op,result,uniqueStrings);
        return result;
    }
};