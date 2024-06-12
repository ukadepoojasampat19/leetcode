class Solution {
public:
    string decodeString(string s) {
            stack<int> numberStack;
        stack<string> stringStack;

        string currentString = "";
        int currentNumber = 0;

        for (char &ch : s) {
            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');  // Build the current number
            } else if (ch == '[') {
                numberStack.push(currentNumber);
                stringStack.push(currentString);
                // Reset currentString and currentNumber
                currentString = "";
                currentNumber = 0;
            } else if (ch == ']') {
                string temp = currentString;
                currentString = stringStack.top();
                stringStack.pop();
                int repeatTimes = numberStack.top();
                numberStack.pop();
                // Repeat the temp string and append to currentString
                for (int i = 0; i < repeatTimes; ++i) {
                    currentString += temp;
                }
            } else {
                currentString += ch;  // Append character to currentString
            }
        }

        return currentString;

    }
};