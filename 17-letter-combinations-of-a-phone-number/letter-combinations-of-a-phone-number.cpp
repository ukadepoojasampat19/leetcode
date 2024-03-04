
class Solution {
public:

    void backtrack(const string& digits, int index, const map<char, string>& num,
                   string& currentCombination, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }

        char currentDigit = digits[index];
        const string& letters = num.at(currentDigit);

        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, num, currentCombination, result);
            currentCombination.pop_back();  
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        map<char, string> num;
        num['2'] = "abc";
        num['3'] = "def";
        num['4'] = "ghi";
        num['5'] = "jkl";
        num['6'] = "mno";
        num['7'] = "pqrs";
        num['8'] = "tuv";
        num['9'] = "wxyz";

        vector<string> result;
        string currentCombination;

        backtrack(digits, 0, num, currentCombination, result);

        return result;
    }


};