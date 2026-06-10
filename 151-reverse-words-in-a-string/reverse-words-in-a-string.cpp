class Solution {
public:
    string reverseWords(string s) {

        string result = "";
        string curr = "";

        for(char ch : s){

            if(ch != ' '){

                curr += ch;

            }else{

                if(curr != ""){

                    result = curr + " " + result;
                    curr = "";
                }
            }
        }

        if(curr != ""){
            result = curr + " " + result;
        }

        while(!result.empty() && result.back() == ' '){
            result.pop_back();
        }

        return result;
    }
};