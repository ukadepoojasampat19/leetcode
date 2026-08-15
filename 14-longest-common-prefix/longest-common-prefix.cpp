class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if(strs.empty()) return "";

        for(int i=0;i<strs[0].size();i++){
            char currChar= strs[0][i];

            for(int j=1;j<strs.size();j++){
                if(currChar != strs[j][i]){
                    return result;

                }


            }
                            result += currChar;

        }
        return result;

    }
};