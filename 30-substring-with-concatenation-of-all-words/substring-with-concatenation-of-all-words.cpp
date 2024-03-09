
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordSize = words[0].length();
        int wordCount = words.size();
        int totalSize = wordSize * wordCount;
        unordered_map<string, int> wordFreq;

        // Populate the frequency of each word in the words array
        for (const string& word : words) {
            wordFreq[word]++;
        }

        for (int i = 0; i < wordSize; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> currentFreq;

            while (right + wordSize <= s.length()) {
                string currentWord = s.substr(right, wordSize);
                right += wordSize;

                if (wordFreq.find(currentWord) != wordFreq.end()) {
                    currentFreq[currentWord]++;
                    count++;

                    while (currentFreq[currentWord] > wordFreq[currentWord]) {
                        string leftWord = s.substr(left, wordSize);
                        left += wordSize;
                        count--;
                        currentFreq[leftWord]--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    currentFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
