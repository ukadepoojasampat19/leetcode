class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int targetIdx=0;
        int targetlen = str2.length();

        for(char ch : str1)
        {
            if(targetIdx < targetlen && (str2[targetIdx] - ch +26) %26 <=1)
            {
                targetIdx++;
            }
        }
        return targetIdx == targetlen;
    }
};